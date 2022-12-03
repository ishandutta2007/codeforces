#include <bits/stdc++.h>
#define MOD1 998244353
#define MOD2 1000000009
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,s,p,q,a,b,c,x,y,z;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        k=1e9;
        for(i=1;i<=15000;i++) {
            l=abs(b-i);
            s=1e9;
            for(j=1;j<=sqrt(i);j++) {
                if (i%j==0) {
                    if (abs(a-j)<s) {
                        s=abs(a-j);
                        p=j;
                    }
                    if (abs(a-i/j)<s) {
                        s=abs(a-i/j);
                        p=i/j;
                    }
                }
            }
            l+=s;
            if (c-c/i*i<=i/2) {
                q=c/i*i;
                l+=c-c/i*i;
            }
            else {
                q=c/i*i+i;
                l+=c/i*i+i-c;
            }
            if (l<k) {
                k=l;
                x=p;
                y=i;
                z=q;
            }
        }
        cout<<k<<endl;
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
    return 0;
}