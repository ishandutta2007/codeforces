#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,L,ans,v,sum,A[MN],B[MN];
char c;
string S;

int main()
{
    //ios_base::sync_with_stdio(0),cin.tie(0);
    while(1){
        cin >> S;
        if(S[0]=='m') break;
        if(S[0]=='e') break;
        long long s = 1, e = INF;
        while(s+1<e){
            //cout << s << ' ' << e << '\n';
            if(e>3*s) v = s;
            else v = (s+e)/4;
            cout << '?' << ' ' << v << ' ' << 2*v << '\n';
            fflush(stdout);
            cin >> c;
            if(c=='x') e = 2*v;
            else s = 2*v+1;
            if(c=='e') exit(0);
        }
        if(e==s+1){
            if(s==1) cout << '?' << ' ' << 2 << ' ' << 3 << '\n';
            else cout << '?' << ' ' << s << ' ' << e << '\n';
            fflush(stdout);
            cin >> c;
            if(s==1 && c=='x') e = s;
            if(s==1 && c=='y') s = e;
            if(c=='x') s = e;
            else e = s;
            if(c=='e') exit(0);
        }
        long long a = s;
        cout << '!' << ' ' << a << '\n';
    }
}