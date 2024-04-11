#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y;
    long long a[200010],b[200010],ans;
    cin>>n;
    ans=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        ans+=a[i];
    }
    sort(a,a+n);
    cin>>m;
    for(i=0;i<m;i++) {
        cin>>x>>y;
        k=upper_bound(a,a+n,x)-a;
        if (k<n&&a[k]>=x&&ans-a[k]>=y) {
            cout<<0<<endl;
            continue;
        }
        if (k==0) {
            cout<<y-ans+a[0]<<endl;
        }
        else if (k<n){
            cout<<min(x-a[k-1]+max(0ll,y-ans+a[k-1]),max(0ll,y-ans+a[k]))<<endl;
        }
        else {
            cout<<(x-a[k-1]+max(0ll,y-ans+a[k-1]))<<endl;
        }
    }
    return 0;
}