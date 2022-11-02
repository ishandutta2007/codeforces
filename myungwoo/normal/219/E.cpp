#include <stdio.h>
#include <set>
using namespace std;

#define MAXN 200005
#define MAXK 1000006

int N,M,RT;
int pos[MAXK];

struct RANGE{
    RANGE(){}
    RANGE(int s,int e){
        this->s = s; this->e = e;
        if (s == 1){
            x = 1;
            max = e;
        }else if (e == N){
            x = N;
            max = x-s+1;
        }else{
            x = (s+e)/2;
            max = x-s+1;
        }
    }
    int s,e;
    int max,x;
    bool operator < (const RANGE &b)const{
        return max!=b.max?max>b.max:x<b.x;
    }
};

set <int> P;
set <int>::iterator pit;

set <RANGE> S;
set <RANGE>::iterator it;

int main()
{
    int k,n,x,a,b;
    scanf("%d%d",&N,&M);
    S.insert(RANGE(1,N));
    P.insert(0), P.insert(N+1);
    while (M--){
        scanf("%d%d",&k,&n);
        if (k == 1){
            it = S.begin();
            pos[n] = it->x;
            printf("%d\n",it->x);
            if (it->x > it->s) S.insert(RANGE(it->s,it->x-1));
            if (it->x < it->e) S.insert(RANGE(it->x+1,it->e));
            P.insert(it->x);
            S.erase(it);
        }else{
            x = pos[n];
            P.erase(x);
            pit = P.lower_bound(x+1);
            b = *pit; --pit;
            a = *pit;
            if (x+1 < b) S.erase(RANGE(x+1,b-1));
            if (a+1 < x) S.erase(RANGE(a+1,x-1));
            S.insert(RANGE(a+1,b-1));
        }
    }
}