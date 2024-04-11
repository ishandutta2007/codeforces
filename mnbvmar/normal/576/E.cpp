#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

/////////////////////////////////////////////////////////


template<typename T>
struct RevertibleVector {
    vector<T> data;
    vector<pair<int,T>> changes;
    int curState;                  // number of operations done
    
    RevertibleVector() : curState(0) {}
    RevertibleVector(int size) : curState(0) {
        data.resize(size);
    }

    void resize(int size){
        data.resize(size);
    }

    int getState() const {
        return curState;
    }

    T get(int pos) const {
        return data[pos];
    }

    T operator[](int pos) const {
        return data[pos];
    }

    void set(int pos, T value){
//        debug("set", pos);
        changes.emplace_back(pos, data[pos]);
        data[pos] = value;
        curState++;
//        debug(curState);
    }

    void revert(int prevState){
        for(int nxt = curState-1; nxt >= prevState; nxt--){
            data[changes[nxt].first] = changes[nxt].second;
            changes.pop_back();
        }
        curState = prevState;
    }
};

struct FUInfo {   // information about find&union vertex
    int parent;      // parent in tree
    int treeSize;    // subtree size (up-to-date only for roots)
    bool invert;     // are vertex and its f&u parent in distinct parts?
};

struct RevertibleFindUnionWithParity {
    RevertibleVector<FUInfo> data;

    RevertibleFindUnionWithParity() {}
    RevertibleFindUnionWithParity(int N){
        data.resize(N);
        for(int i = 0; i < N; i++){
            data.data[i] = FUInfo{i, 1, false};
        }
    }

    // find root set and check if v and the root are in distinct parts
    pair<int, bool> findSet(int v) const {
//        dbg();
        bool curNeg = false;
        while(v != data[v].parent){
            curNeg ^= data[v].invert;
            v = data[v].parent;
        }
        return {v, curNeg};
    }

    // add edge between 'u' and 'v'; returns 'false' if this leads to
    // contradiction
    bool unionSets(int u, int v){
        bool negU, negV;
        tie(u, negU) = findSet(u);
        tie(v, negV) = findSet(v);

        if(u == v) return (negU != negV);   // nothing to do
        if(data[u].treeSize < data[v].treeSize) swap(u,v);  // say 'v' subtree is smaller

        // connect 'v' with 'u'
        //data[v].parent    = u;
        //data[u].treeSize += data[v].treeSize;
        //data[v].invert    = !(negU ^ negV);
        int vSize = data[v].treeSize, uSize = data[u].treeSize;
        data.set(v, FUInfo{u, -1, !(negU ^ negV)});
        data.set(u, FUInfo{u, vSize+uSize, false});
        return true;
    }

    int getState() const {
        return data.getState();
    }

    void revert(int state){
//        debug("revert", state);
        data.revert(state);
//        dbg();
    }

    void dbg() const {
        for(auto P : data.data){
            printf("(%d,%d,%d) ", P.parent, P.treeSize, P.invert);
        }
        printf("\n");
    }
};

const int MaxVerts   = 500005,
          MaxEdges   = 500005,
          MaxQueries = 500005,
          MaxColors  = 52;

int numVerts, numEdges, numQueries, numColors;
vector<int> edgeFrom, edgeTo;
vector<int> queryEdge, queryCol;
vector<int> nextSameEdge;
vector<RevertibleFindUnionWithParity> FU;
vector<vector<pair<int,int>>> paintingTree;   // tree containing painting edge actions
vector<int> curColor;
int Base;


void input(){
    scanf("%d%d%d%d", &numVerts, &numEdges, &numColors, &numQueries);
    
    edgeFrom.resize(numEdges);
    edgeTo.resize(numEdges);
    for(int edge = 0; edge < numEdges; edge++){
        scanf("%d%d", &edgeFrom[edge], &edgeTo[edge]);
        edgeFrom[edge]--;
        edgeTo[edge]--;
    }

    queryEdge.resize(numQueries);
    queryCol.resize(numQueries);
    for(int query = 0; query < numQueries; query++){
        scanf("%d%d", &queryEdge[query], &queryCol[query]);
        queryEdge[query]--;
        queryCol[query]--;
    }
    debug(sizeof(FUInfo));

    FU.resize(numColors, RevertibleFindUnionWithParity(numVerts));
/*    FU.resize(numColors);
    for(int i = 0; i < numColors; i++) FU[i].resize(numVerts);*/
//    debug(1); sleep(10);
}

// for each edge find its next occurence in queries (or Q if there's no)
void process_queries_by_edges(){
    vector<int> firstOccur(numEdges, numQueries);
    nextSameEdge.resize(numQueries);

    for(int query = numQueries-1; query >= 0; query--){
        int edge = queryEdge[query];
        nextSameEdge[query] = firstOccur[edge];
        firstOccur[edge] = query;
    }
}


// build segment tree with edge-painting queries
void build_tree(){
    Base = 1;
    while(Base < numQueries+1) Base *= 2;
    paintingTree.resize(Base*2);
}

void update_tree(int left, int right, pair<int,int> op){
    debug("update_tree", left, right, op.first, op.second);
    if(left > right) return;
    left += Base; right += Base;
    paintingTree[left].push_back(op);
    if(left != right) paintingTree[right].push_back(op);

    while(left/2 != right/2){
        if(left % 2 == 0) paintingTree[left+1].push_back(op);
        if(right % 2 == 1) paintingTree[right-1].push_back(op);
        left /= 2; right /= 2;
    }
}

int maxSum;

void traverse_tree(int vert, int leftIntv, int rightIntv){
//    debug(vert, leftIntv, rightIntv);
    if(leftIntv >= numQueries) return;

    vector<int> lastState(numColors);
    int sumStates = 0;
    for(int i = 0; i < numColors; i++){
        lastState[i] = FU[i].getState();
        sumStates += lastState[i];
    }
    maxSum = max(maxSum, sumStates);

    // process all painting queries
    for(pair<int,int> query : paintingTree[vert]){
        int edge  = query.first,
            color = query.second;
        assert(FU[color].unionSets(edgeFrom[edge], edgeTo[edge]));
    }

    // if at leaf, check if adding queried edge ruins everything
    if(leftIntv == rightIntv){
        assert(vert >= Base);
        int edge  = queryEdge[leftIntv],
            color = queryCol[leftIntv];
//        bool dbg = (edge == 0 && color == 1);

        auto from = FU[color].findSet(edgeFrom[edge]),
             to   = FU[color].findSet(edgeTo[edge]);

//        if(dbg){
//            debug(from.first, from.second, to.first, to.second);
//        }

        int newColor = curColor[edge];

        // edge connects same sets in same part
        if(from == to){
            printf("NO\n");
        } else {
            printf("YES\n");
            newColor = color;
        }

        if(newColor != -1){
            int intvFrom = leftIntv+1,
                intvTo   = nextSameEdge[leftIntv]-1;
            update_tree(intvFrom, intvTo, {queryEdge[leftIntv], newColor});
        }
        curColor[edge] = newColor;
//        debug(edge, curColor[edge]);
    } else {
        // else recurse
        int mid = (leftIntv + rightIntv) / 2;
        traverse_tree(vert*2, leftIntv, mid);
        traverse_tree(vert*2+1, mid+1, rightIntv);
    }


    // revert everything
    for(int i = 0; i < numColors; i++){
//        debug(i, lastState[i]);
        FU[i].revert(lastState[i]);
    }

    // we can clear the node
    paintingTree[vert].clear();
}


int main(){
    input();
    process_queries_by_edges();
    build_tree();
    curColor = vector<int>(numEdges, -1);

    traverse_tree(1, 0, Base-1);
    debug(maxSum);
}