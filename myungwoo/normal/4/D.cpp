#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 300005

int N,M,W,H,P[MAXN],lst[MAXN],cnt;
vector <int> path;

struct Z{
    int w,h,idx;
    bool operator < (const Z &b)const{
        return w!=b.w?w<b.w:h>b.h;
    }
} A[MAXN],T;

int main()
{
    int i,w,h,s,e,m,t;
    scanf("%d%d%d",&M,&W,&H);
    for (i=1;i<=M;i++){
        scanf("%d%d",&w,&h);
        if (w > W && h > H) A[++N].w = w, A[N].h = h, A[N].idx = i;
    }
    sort(A+1,A+N+1);
    for (i=1;i<=N;i++){
        s = 1, e = cnt, t = cnt+1;
        while (s <= e){
            m = (s+e)>>1;
            if (A[lst[m]].h >= A[i].h) e = m-1, t = m;
            else s = m+1;
        }
        lst[t] = i;
        if (cnt < t) cnt = t;
        P[i] = lst[t-1];
    }
    for (i=lst[cnt];i;i=P[i]) path.push_back(A[i].idx);
    printf("%d\n",cnt);
    for (i=path.size();i--;) printf("%d ",path[i]);
}