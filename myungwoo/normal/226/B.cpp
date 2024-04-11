#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

#define MAXN 100005
typedef long long lld;
typedef pair<int,int> pii;

int N,M,K,A[MAXN]; lld S[MAXN],ans[MAXN];
vector <pii> Q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,t;
    lld j,k,bef;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    sort(A+1,A+N+1,greater<int>());
    for (i=1;i<=N;i++) S[i] = A[i]+S[i-1];
    scanf("%d",&M);
    for (i=1;i<=M;i++) scanf("%d",&t), Q.push_back(pii(t,i));
    sort(Q.begin(),Q.end());
    for (i=0;i<M;i++){
        if (!i || Q[i].first != Q[i-1].first){
            K = Q[i].first; bef = 0;
            for (j=k=1,t=0;j<=N;t++,k*=K){
                bef += (S[min(lld(N),j+k-1)]-S[j-1])*t;
                j += k;
            }
        }
        ans[Q[i].second] = bef;
    }
    for (i=1;i<=M;i++) printf("%I64d ",ans[i]);
}