#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll s;
pair<ll,ll> p[202020];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %lld",&n,&s);

        for(int i=1;i<=n;i++) scanf("%lld %lld",&p[i].first,&p[i].second);
        for(int i=1;i<=n;i++) s-=p[i].first;
        sort(p+1, p+1+n, greater<pair<int,int>>());

        ll l=1, r=1000000001;
        while(l<=r){
            ll mid = (l+r)/2, m = 0;
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(p[i].second < mid) continue;

                ll pl = mid - p[i].first;
                m += max(pl, 0ll);

                if(m > s){
                    cnt = 0;
                    break;
                }

                if(++cnt >= n/2+1) break;
            }
            if(cnt >= n/2+1) l = mid+1;
            else r = mid-1;
        }
        printf("%lld\n",l-1);
    }
}