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

const int MX=3e5;
ll q, h, n, p[MX];
ll mem[MX];

ll getAns(ll i) {
    if(mem[i] == -1) {
        //fall
        ll ground = p[i+2];
        ll y    = p[i+1]+1;
        ll fall = y - ground;

        //dont fall
        mem[i] = getAns(i+1)+1;
        if(fall <= 2) mem[i] = min(mem[i], getAns(i+2));
    }
    return mem[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>h>>n;
        RE(i,n) cin>>p[i];
        REP(i,n,n+5) p[i]=0;
        RE(i,n) mem[i] = -1;
        REP(i,n,n+5) mem[i]=0;
        cout<<getAns(0)<<endl;
    }
}