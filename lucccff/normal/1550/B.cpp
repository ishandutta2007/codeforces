#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    long long a,b;
    string s;
    char c;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>a>>b;
        cin>>s;
        l=s.size();
        if (b==0) {
            cout<<a*l<<endl;
        }
        else if (b>0) {
            cout<<a*l+l*b<<endl;
        }
        else {
            j=0;
            k=0;
            while(j<l) {
                k++;
                c=s[j];
                while(j<l&&s[j]==c) j++;
            }
            cout<<a*l+b*(k/2)+b<<endl;
        }
    }
    return 0;
}