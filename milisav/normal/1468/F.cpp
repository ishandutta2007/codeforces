#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        mp.clear();
        scanf("%d",&n);
        int x,y,u,v;
        long long ans=0;
        while(n--) {
            scanf("%d %d %d %d",&x,&y,&u,&v);
            int dx=u-x;
            int dy=v-y;
            int g=__gcd(dx,dy);
            g=abs(g);
            dx/=g;
            dy/=g;
            ans=ans+mp[{-dx,-dy}];
            mp[{dx,dy}]+=1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}