#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,f;
    string s;
    cin>>t;
    for(i=0;i<t;i++) {
        k=1;
        cout<<1<<' '<<2<<endl<<flush;
        cin>>s;
        j=2;
        if (s[2]=='n') continue;
        while(1) {
            while(1) {
                f=1;
                if (j==1) j++;
                else j=1; 
                for(;j<=8;j++) {
                    cout<<k<<' '<<j<<endl<<flush;
                    cin>>s;
                    if (s[2]=='n'||s[0]=='D') break;
                    if (s[0]=='U') f=0;
                }
                if (s[2]=='n'||s[0]=='D'||f) break;
            }
            if (j==9) j--;
            if (s[2]=='n') break;
            if (s[0]=='D'||f) k++;
            if (s[0]=='D') f=1;
            if (k>8) break;
            while(f) {
                f=0;
                cout<<k<<' '<<j<<endl<<flush;
                cin>>s;
                if (s[2]=='n') break;
                if (s[0]=='D'||f) {
                    k++;
                    f=1;
                }
                if (k>8) break;
            }
            if (s[2]=='n') break;
            if (k>8) break;
        }
    }
    return 0;
}