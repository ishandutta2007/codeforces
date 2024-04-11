#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

typedef unsigned long long hash_t;
inline hash_t hash_random() { hash_t answer=0; for (int i=0;i<5;++i) answer<<=15,answer^=rand(); return answer; }
struct edge { int x,y; };

int main() {
    int N, M; scanf("%d%d",&N,&M);
    vector<edge> E(M);
    for (int m=0; m<M; ++m) { scanf("%d%d",&E[m].x,&E[m].y); --E[m].x; --E[m].y; }

    vector<hash_t> personal_hash(N), friends_hash(N,0);
    generate( personal_hash.begin(), personal_hash.end(), hash_random );
    for (int m=0; m<M; ++m) {
        friends_hash[ E[m].x ] ^= personal_hash[ E[m].y ];
        friends_hash[ E[m].y ] ^= personal_hash[ E[m].x ];
    }
    
    long long answer = 0;
    
    for (int m=0; m<M; ++m) 
        if ((friends_hash[ E[m].x ] ^ personal_hash[ E[m].x ]) == 
            (friends_hash[ E[m].y ] ^ personal_hash[ E[m].y ])) ++answer;
   
    map<hash_t,int> cnt;
    for (int n=0; n<N; ++n) answer += cnt[friends_hash[n]]++; 
    cout << answer << endl;
}