#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 200005;

int fu_root[MaxN];
int fu_right_all[MaxN], fu_right_int[MaxN], fu_size[MaxN];
vector<vector<int>> whoIs;
set<pair<int,int>> intervals;

void fu_init(int N){
    iota(fu_root, fu_root+N+1, 0);
    iota(fu_right_int, fu_right_int+N+1, 0);
    iota(fu_right_all, fu_right_all+N+1, 0);
    fill(fu_size, fu_size+N+1, 1);
    for(int i = 0; i <= N+1; i++){
        whoIs.emplace_back();
        whoIs.rbegin()->push_back(i);
        intervals.insert(make_pair(i,i));
    }
}

int fu_find(int v){
    return fu_root[v];
}

set<pair<int,int>>::iterator containing(int p){
    auto it = intervals.upper_bound(make_pair(p, (int)1e9));
    assert(it != intervals.begin());
    return prev(it);
}

int N, Q;
void join_ints(int p, int q){
//    printf("join(%d,%d)\n", p, q);
    auto it1 = containing(p),
         it2 = containing(q);

    if(it1 == it2) return;

    int L = it1->first,
        R = it2->second;
    
//    printf("L=%d R=%d\n", L, R);

    intervals.erase(it1);
    intervals.erase(it2);
    intervals.insert(make_pair(L,R));
}

void fu_union(int a, int b){
    a = fu_find(a);
    b = fu_find(b);
    if(a == b) return;

    if(fu_size[a] > fu_size[b]) swap(a, b);

    // a to b
    for(int t : whoIs[a]){
        fu_root[t] = b;
        whoIs[b].push_back(t);
        if(t != 0 && fu_root[t-1] == fu_root[t]){
            join_ints(t-1, t);
        }
        if(t != N && fu_root[t+1] == fu_root[t]){
            join_ints(t, t+1);
        }
    }
    fu_size[b] += fu_size[a];
    whoIs[a].clear();
}



void input(){
    scanf("%d%d", &N, &Q);
}

int main(){
    input();
    fu_init(N);
    for(int query = 1; query <= Q; query++){
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
//        printf("%d %d %d\n", type, x, y);
        int position;
        switch(type){
            case 1:
                fu_union(x, y);
                break;

            case 2:
                position = x;
                while(position <= y){
                    if(position != x) fu_union(x, position);
                    position = containing(position)->second + 1;
//                    printf("pos = %d\n", position);
                }
                break;

            case 3:
                printf(fu_find(x) == fu_find(y) ? "YES\n" : "NO\n");
                break;
        }

//        for(auto P : intervals){
//            printf("%d,%d\n", P.first, P.second);
//        }
//        for(int i = 1; i <= N; i++){
//            printf("%d ", fu_root[i]);
//        }
//        printf("\n");
    }
}