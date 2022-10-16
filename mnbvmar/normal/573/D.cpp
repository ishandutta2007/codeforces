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
#define debug(...) {}
#endif

/////////////////////////////////////////////////////////


const LL Infty = 1e18;
const int MaxN = (1<<15);

struct Node {
    LL scores[3][3];
    int left, right;

    Node(){
        for(int i = 0; i < 3; i++){
            for(int j =0 ; j < 3; j++){
                scores[i][j] = -Infty;
            }
        }
        left = right = -1;
    }
};


int badHorse[MaxN];
int mappingMen[MaxN];
int mappingHorses[MaxN];
LL pointsMen[MaxN], pointsHorses[MaxN];

LL find_best(int left, int right){
    if(left == right+1) return 0;
    assert(left <= right);
    assert(right - left <= 3);
    
    vector<int> perm(right-left+1);
    iota(perm.begin(), perm.end(), 0);
    LL result = -Infty;

    do {
        bool ok = true;
        for(int i = 0; i < (int)perm.size(); i++){
            if(badHorse[left+i] == left+perm[i]) ok = false;
        }
        if(ok){
            LL nowRes = 0;
            for(int i = 0; i < (int)perm.size(); i++){
                nowRes += pointsMen[left+i] * pointsHorses[left+perm[i]];
            }
            result = max(result, nowRes);
        }
    } while(next_permutation(perm.begin(), perm.end()));
    debug("find_best", left, right, result);
    return result;
}

Node merge(const Node& L, const Node& R){
    if(L.left == -1) return R;
    if(R.left == -1) return L;

    Node result;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result.scores[i][j] = -Infty;
        }
    }

    for(int finCutL = 0; finCutL < 3; finCutL++){
        for(int finCutR = 0; finCutR < 3; finCutR++){
            for(int midCutR = 0; midCutR < 3; midCutR++){
                for(int midCutL = 0; midCutL < 3; midCutL++){
                    int dist = midCutR + midCutL;
                    if(dist != 0 && dist != 2 && dist != 3) continue;
                    int lft = L.right - midCutR + 1,
                        rgt = R.left + midCutL - 1;
                    result.scores[finCutL][finCutR] =
                        max(result.scores[finCutL][finCutR],
                                L.scores[finCutL][midCutR]
                              + R.scores[midCutL][finCutR]
                              + find_best(lft, rgt));
                    debug(finCutL, finCutR, midCutR, midCutL,
                            result.scores[finCutL][finCutR]);
                }
            }
        }
    }

    result.left = L.left;
    result.right = R.right;
    return result;
}


int N, Q;

void input(){
    ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> pointsMen[i];
    }
    for(int i = 0; i < N; i++){
        cin >> pointsHorses[i];
    }
}

void preprocess_arrays(){
    vector<int> orderMen(N);
    iota(orderMen.begin(), orderMen.end(), 0);
    sort(orderMen.begin(), orderMen.end(), [&](int lhs, int rhs){
                return make_pair(pointsMen[lhs], lhs)
                     < make_pair(pointsMen[rhs], rhs);
            });

    for(int i = 0; i < N; i++){
        mappingMen[orderMen[i]+1] = i;
    }


    vector<int> orderHorses(N);
    iota(orderHorses.begin(), orderHorses.end(), 0);
    sort(orderHorses.begin(), orderHorses.end(), [&](int lhs, int rhs){
                return make_pair(pointsHorses[lhs], lhs)
                     < make_pair(pointsHorses[rhs], rhs);
            });
    for(int i = 0; i < N; i++){
        mappingHorses[orderHorses[i]+1] = i;
    }

    for(int i = 1; i <= N; i++){
        badHorse[mappingMen[i]] = mappingHorses[i];
    }

    sort(pointsHorses, pointsHorses+N);
    sort(pointsMen, pointsMen+N);
}


Node tree[MaxN];
const int Base = MaxN/2;


void propag(int L, int R){
    L /= 2; R /= 2;
    while(L){
        for(int i = L; i <= R; i++){
            tree[i] = merge(tree[i*2], tree[i*2+1]);
            debug(i, tree[i].scores[0][0]);
        }
        L /= 2; R /= 2;
    }
}

void recalc_leaf(int num){
    int left = num*4,
        right = min(N-1, num*4+3);
    int len = right-left+1;

    for(int cutL = 0; cutL < 3; cutL++){
        for(int cutR = 0; cutR < 3; cutR++){
            if(cutL+cutR > len) continue;
            tree[Base+num].scores[cutL][cutR] = find_best(left+cutL, right-cutR);
            debug(num, cutL, cutR, tree[Base+num].scores[cutL][cutR]);
        }
    }
}

void recalc_up(int num){
    num = (Base+num)/2;
    while(num){
        tree[num] = merge(tree[num*2], tree[num*2+1]);
        num /= 2;
        debug(num, tree[num].scores[0][0]);
    }
}


int main(){
    input();
    preprocess_arrays();
    for(int i = 0; i < N; i++){
        debug(i, badHorse[i]);
    }

    for(int i = 0; i < (N+3)/4; i++){
        recalc_leaf(i);
        
        tree[Base+i].left = i*4;
        tree[Base+i].right = min(N-1, i*4+3);
    }

    propag(Base, Base+(N+3)/4);

    debug(tree[1].scores[0][0]);
    for(int query = 1; query <= Q; query++){
        int p, q;
        cin >> p >> q;
        p = mappingMen[p];
        q = mappingMen[q];
        swap(badHorse[p], badHorse[q]);
        recalc_leaf(p/4); recalc_up(p/4);
        recalc_leaf(q/4); recalc_up(q/4);

        cout << tree[1].scores[0][0] << "\n";
    }
}