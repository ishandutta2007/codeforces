#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int turn(string s,int t,int l1,int l2) {
    if (l1>l2+(10-t+1)/2||l2>l1+(10-t)/2) return t;
    if (t==10) return t;
    int m,n;
    if (t&1) {
        if (s[t]=='1') return turn(s,t+1,l1,l2+1);
        else if (s[t]=='0') return turn(s,t+1,l1,l2);
        else {
            return min(turn(s,t+1,l1,l2+1),turn(s,t+1,l1,l2));
        }
    }
    else {
        if (s[t]=='1') return turn(s,t+1,l1+1,l2);
        else if (s[t]=='0') return turn(s,t+1,l1,l2);
        else {
            return min(turn(s,t+1,l1+1,l2),turn(s,t+1,l1,l2));
        }
    }
} 

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<turn(s,0,0,0)<<endl;
    }
    return 0;
}