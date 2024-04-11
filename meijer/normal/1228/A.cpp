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

const int MX=1e5;
int l, r;
bitset<10> used;

bool pos(int i) {
    stringstream ss;
    ss<<i;
    string s = ss.str();
    used.reset();
    RE(i,s.size()) {
        if(used[s[i]-'0']) return 0;
        used[s[i]-'0'] = 1;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r;
    REP(i,l,r+1) {
        if(pos(i)) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}