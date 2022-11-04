#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,chk[202020],cnt,fl;
ll ans,a;
priority_queue<pair<ll,int>> pq;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        pq.push({a,i});
    }
    for(int i=1;i<=m*k;i++){
        chk[pq.top().second]=1;
        ans+=pq.top().first;
        pq.pop();
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        cnt+=chk[i];
        if(cnt == m){
            fl++;
            if(fl == k) return 0;
            printf("%d ",i);
            cnt=0;
        }
    }
}