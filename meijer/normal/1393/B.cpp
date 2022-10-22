#include <bits/stdc++.h>
using namespace std;

// macros
typedef long long ll;
typedef long double ld;
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
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }

// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi," ",x.se);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }

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
int n, a[MX];
int q, x[MX];
char c[MX];
map<int, int> cnt;
map<int, set<int>> mp;
vi temp;

void add(int x) {
    mp[cnt[x]].erase(x);
    if(mp[cnt[x]].empty()) mp.erase(cnt[x]);
    cnt[x]++;
    mp[cnt[x]].insert(x);
}
void remove(int x) {
    mp[cnt[x]].erase(x);
    if(mp[cnt[x]].empty()) mp.erase(cnt[x]);
    cnt[x]--;
    if(cnt[x] != 0)
        mp[cnt[x]].insert(x);
}
int getBest() {
    if(mp.empty()) return -1;
    return *(--((--mp.end())->se.end()));
}
bool possible() {
    int bst = getBest();
    if(bst == -1) return 0;
    if(cnt[bst] < 4) return 0;
    RE(i,4) remove(bst), temp.pb(bst);
    RE(i,2) {
        bst = getBest();
        if(cnt[bst] < 2) return 0;
        RE(j,2) remove(bst), temp.pb(bst);
    }
    return 1;
}

void program() {
    IN(n);
    RE(i,n) IN(a[i]);
    IN(q);
    RE(i,q) IN(c[i],x[i]);

    RE(i,n) add(a[i]);
    RE(i,q) {
        if(c[i] == '+') add(x[i]);
        else remove(x[i]);
        OUTL(possible() ? "YES" : "NO");
        FOR(x,temp) add(x);
        temp.clear();
    }
}