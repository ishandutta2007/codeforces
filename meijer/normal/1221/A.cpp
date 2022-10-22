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

const int MX=1e5;
int q, n;
ll s;
bitset<12> found;

void addFound(int i) {
    if(found[i]) {
        if(i==11) return;
        found[i] = 0;
        addFound(i+1);
    } else found[i] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    RE(i,q) {
        found.reset();
        cin>>n;
        RE(i,n) {
            cin>>s; if(s>2048) continue;
            RE(i,12) if(s&(1<<i)) addFound(i);
        }
        cout<<(found[11]?"YES":"NO")<<endl;
    }
}