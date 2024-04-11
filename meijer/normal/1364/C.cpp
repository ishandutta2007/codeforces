#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, a[MX], b[MX];
set<int> s;

int getLast(int i) {
    if(i == 0) return 0;
    return a[i-1];
}

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    
    bool pos = 1;
    REP(i,1,n) if(a[i] < a[i-1]) pos = 0;
    RE(i,n) if(a[i] > i+1) pos = 0;
    if(!pos) {
        cout<<-1<<endl;
        return;
    }
    a[n] = a[n-1]+1; n++;
    RE(i,n) s.insert(i);

    RE(i,n) b[i] = -1;
    RE(i,n) {
        if(a[i] != getLast(i)) {
            b[i] = getLast(i);
            s.erase(b[i]);
        }
    }
    RE(i,n) if(b[i] == -1) b[i] = *s.begin(), s.erase(b[i]);

    RE(_pi,n-1) cout<<(_pi==0?"":" ")<<b[_pi]; cout<<endl;
}