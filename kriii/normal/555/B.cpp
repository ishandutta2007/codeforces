#include <stdio.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct intv{
    intv(long long s_, long long e_, int i_){
        s = s_; e = e_; i = i_;
    }
    long long s,e; int i;
    bool operator <(const intv t) const{
        return s > t.s;
    }
};

struct brid{
    long long l; int i;
    bool operator <(const brid t) const{return l < t.l;}
}B[200005];

int N,M; long long A[200005];

int main()
{
    priority_queue<intv> Q,R;

    scanf ("%d %d",&N,&M);
    long long l,r;
    for (int i=0;i<N;i++){
        long long x,y;
        scanf ("%lld %lld",&x,&y);
        if (i){
            long long mx = y - l, mn = x - r;
            Q.push(intv(mn,mx,i));
        }
        l = x; r = y;
    }

    for (int i=0;i<M;i++) scanf ("%lld",&B[i].l), B[i].i = i+1;
    sort(B,B+M);

    int p = 0;
    for (int i=0;i<M;i++){
        while (!Q.empty() && Q.top().s <= B[i].l){
            R.push(intv(Q.top().e,0,Q.top().i)); Q.pop();
        }
        while (!R.empty() && R.top().s < B[i].l) R.pop();
        if (!R.empty()){
            A[R.top().i] = B[i].i;
            R.pop();
            p++;
        }
    }

    if (p == N-1){
        puts("Yes");
        for (int i=1;i<N;i++) printf ("%lld ",A[i]);
    }
    else puts("No");

    return 0;
}