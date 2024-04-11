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

const int MX = 7e5;
ll n, a[MX], m;
ll tot=0, ans=0;

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) a[n+i] = a[i];
    RE(i,n) a[n*2+i] = a[i];
    m = n*3;
    queue<ll> q;
    RE(i,m) {
        if(i%2) {
            tot += a[i];
            q.push(a[i]);
            if(q.size() > (n+1)/2) {
                tot -= q.front();
                q.pop();
            }
        }
        ans = max(ans, tot);
    }
    cout<<ans<<endl;
}