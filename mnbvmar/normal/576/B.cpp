#include <bits/stdc++.h>

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

const int MaxN = 100005;

int N;
int perm[MaxN];
vector<vector<int>> cycles[MaxN];
bool vis[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &perm[i]);
    }
}

void mkcyc(){
    for(int i = 1; i <= N; i++){
        if(vis[i]) continue;
        int p = i;
        vector<int> curCyc;
        do {
            curCyc.push_back(p);
            p = perm[p];
            vis[p] = true;
        } while(p != i);
        cycles[curCyc.size()].push_back(curCyc);
    }
}

void make1(){
    int v = cycles[1][0][0];
    printf("YES\n");
    for(int i = 1; i <= N; i++){
        if(i != v) printf("%d %d\n", v, i);
    }
}

void make2(){
    vector<int> twoCyc = cycles[2][0];
    cycles[2].erase(cycles[2].begin());

    for(int i = 1; i <= N; i += 2){
        if(cycles[i].size() > 0){ printf("NO\n"); return; }
    }

    vector<int> even, odd;
    for(int i = 2; i <= N; i += 2){
        for(const vector<int>& cyc : cycles[i]){
            bool doEven = true;
            for(int v : cyc){
                if(doEven) even.push_back(v); else odd.push_back(v);
                doEven = !doEven;
            }
        }
    }

    assert(even.size() == odd.size());

    printf("YES\n");
    printf("%d %d\n", twoCyc[0], twoCyc[1]);
    for(int v : even){
        printf("%d %d\n", twoCyc[0], v);
    }
    for(int v : odd){
        printf("%d %d\n", twoCyc[1], v);
    }
}


int main(){
    input();
    mkcyc();
    if(cycles[1].size() > 0){
        make1();
        return 0;
    }
    if(cycles[2].size() > 0){
        make2();
        return 0;
    }
    printf("NO\n");
    return 0;
}