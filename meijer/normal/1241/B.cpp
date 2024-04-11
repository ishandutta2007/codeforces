#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back

const int MX=26;
int q;
bitset<MX> hs, ht;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    RE(i,q) {
        cin>>s>>t;
        if(s == t) cout<<"YES"<<endl;
        else {
            hs.reset(), ht.reset();
            RE(i,s.size()) hs[s[i]-'a'] = 1;
            RE(i,t.size()) ht[t[i]-'a'] = 1;
            bool pos=0;
            RE(i,MX) if(ht[i] && hs[i]) pos = 1;
            cout<<(pos?"YES":"NO")<<endl;
        }
    }
}