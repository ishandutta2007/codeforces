#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int a[100010];
//vector <int> e[100010],f[100010];
int c[100010],d[100010],e[100010],f[100010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t,ans;
    cin>>t;
    while(t--) {
        cin>>n;
        ans=0;
        for(i=0;i<n;i++) {
            cin>>a[i];
            //e[i].clear();
            //f[i].clear();
        }
        //e[n].clear();
        //f[n].clear();
        l=0;
        m=0;
        for(i=n-1;i>=0;i--) {
            l=0;
            for(j=m-1;j>=0;j--) {
                ans+=(a[i]-1)/c[j]*(i+1)*d[j];
                ans%=MOD;
                k=a[i]/((a[i]-1)/c[j]+1);
                if (l&&k==e[l-1]) {
                    f[l-1]+=d[j];
                }
                else {
                    e[l]=k;
                    f[l]=d[j];
                    l++;
                }
            }
            if (l&&a[i]==e[l-1]) {
                f[l-1]++;
            }
            else {
                e[l]=a[i];
                f[l]=1;
                l++;
            }
            for(j=0;j<l;j++) {
                c[j]=e[j];
                d[j]=f[j];
            }
            m=l;
        }
        cout<<ans<<endl;
    }
    return 0;
}