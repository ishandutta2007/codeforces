#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,sa,sb,p;
    long long a[100010],b[100010];
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=0;j<n;j++) {
            cin>>a[j];
        }
        for(j=0;j<n;j++) {
            cin>>b[j];
        }
        sort(a,a+n);
        sort(b,b+n);
        k=n/4;
        l=n;
        sa=sb=0;
        for(j=k;j<l;j++) {
            sa+=a[j];
            sb+=b[j];
        }
        if (sa>=sb) {
            cout<<0<<endl;
            continue;
        }
        p=n/4;
        while(sa<sb) {
            l++;
            sa+=100;
            if (l%4==0) {
                sa-=a[k];
                k++;
            }
            else {
                p--;
                if (p>=0) sb+=b[p];
            }
        }
        cout<<l-n<<endl;
    }
    return 0;
}