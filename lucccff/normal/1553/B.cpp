#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l1,l2,m,n,t,f,x;
    string s1,s2;
    cin>>t;
    while(t--) {
        cin>>s1>>s2;
        l1=s1.length();
        l2=s2.length();
        for(i=0;i<l1;i++) {
            f=1;
            x=0;
            for(j=i;j-i<l2&&j<l1;j++) {
                if (s1[j]!=s2[j-i]) {
                    f=0;
                    break;
                }
                if (j-i==l2-1) {
                    x=1;
                    break;
                }
                for(k=j-1;k>=0;k--) {
                    if (s2[j-i+j-k]!=s1[k]) {
                        break;
                    }
                    if (j-i+j-k==l2-1) {
                        x=1;
                        break;
                    }
                }
                if (x==1) break;
            }
            if (x==1) break;
        }
        if (x==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}