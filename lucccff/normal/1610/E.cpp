#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[200010],b[200010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,mx,n,t,ans;
    cin>>t;
    while(t--) {
        cin>>n;
        for(i=0;i<n;i++) {
            cin>>a[i];
        }
        for(i=0;i<n;i++) {
            b[n-i-1]=a[n-1]+1-a[i];
        }
        for(i=0;i<n;i++) {
            a[i]=b[i];
        }
        m=0;
        ans=0;
        for(i=0;i<n;i++) {
            j=i+1;
            while(j<n&&a[i]==a[j]) j++;
            a[m]=a[i];
            b[m]=j-i;
            ans=max(ans,b[m]);
            m++;
            i=j-1;
        }
        for(i=1;i<m;i++) {
            l=0;
            mx=1;
            while(i-l>1) {
                l=lower_bound(a+l,a+i,(a[l]+a[i]+1)>>1)-a;
                if (l!=i) mx++;
            }
            mx+=b[i];
            ans=max(ans,mx);
        }
        cout<<n-ans<<endl;
    }
    return 0;
}