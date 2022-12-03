#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

pair <int,int> a[200010];
int b[200010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t;
    LL ans;
    cin>>t;
    while(t--) {
        cin>>n;
        ans=0;
        for(i=1;i<=n;i++) {
            cin>>k;
            a[i]=make_pair(-k,i);
        }
        sort(a+1,a+n+1);
        b[0]=0;
        for(i=1;i<=n;i++) {
            if (i&1) {
                b[a[i].second]=(i+1)/2;
            }
            else {
                b[a[i].second]=-i/2;
            }
            ans-=2ll*((i+1)/2)*a[i].first;
        }
        cout<<ans<<endl;
        for(i=0;i<=n;i++) cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}