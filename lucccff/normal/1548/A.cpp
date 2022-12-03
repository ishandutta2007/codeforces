#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,q,x,y;
    long long a[300010],b[300010];
        cin>>n>>m;
        for(j=1;j<=n;j++) a[j]=0;
        for(j=0;j<m;j++) {
            cin>>k>>l;
            if (k>l) a[l]++;
            else a[k]++;
        }
        k=0;
        for(j=1;j<=n;j++) if (a[j]==0) k++;
        cin>>q;
        for(j=0;j<q;j++) {
            cin>>l;
            if (l==3) {
                cout<<k<<endl;
            }
            else if (l==1) {
                cin>>x>>y;
                if (x>y) {
                    if (a[y]++==0) k--;
                }
                else if (a[x]++==0) k--;
            }
            else {
                cin>>x>>y;
                if (x>y) {
                    if (--a[y]==0) k++;
                }
                else if (--a[x]==0) k++;
            }
        }
    return 0;
}