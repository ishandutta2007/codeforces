#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

LL a,b;
LL c[60],r[60];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL i,j,k,l,m,n,t,p,q,s,g;
    cin>>t;
    while(t--) {
        cin>>a>>b>>m;
        if (a==b) {
            cout<<1<<' '<<a<<' '<<endl;
            continue;
        }
        k=1;
        l=1;
        while((a+m)*l<b) {
            l<<=1;
            k++;
        }
        if ((a+1)*l>b) {
            cout<<-1<<endl;
            continue;
        }
        p=b/l-a;
        s=b-(p+a)*l;
        q=0;
        for(i=1;i<k;i++) {
            q=(q<<1)+(s&1);
            s>>=1;
        }
        c[0]=a;
        c[1]=c[0]+p+(q&1);
        g=q&1;
        q>>=1;
        for(i=2;i<=k;i++) {
            c[i]=c[i-1]*2-g+(q&1);
            g=q&1;
            q>>=1;
        }
        cout<<k+1<<' ';
        for(i=0;i<=k;i++) {
            cout<<c[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}