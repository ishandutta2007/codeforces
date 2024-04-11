#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
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
ll n, a[MX];
ll sm[MX], fp[MX];
map<ll, ll> mostRecent;
ll SEG[MX*4];

void buildSeg(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        SEG[p] = fp[l];
        return;
    }
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
    SEG[p] = min(SEG[p*2+1], SEG[p*2+2]);
}
ll getSeg(int i, int j, int p=0, int l=0, int r=n-1) {
    if(j < l || i > r) return INF;
    if(i <= l && j >= r) return SEG[p];
    int m=(l+r)/2;
    ll a = getSeg(i, j, p*2+1,l,m);
    ll b = getSeg(i, j, p*2+2,m+1,r);
    return min(a,b);
}

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    sm[0] = 0;
    RE(i,n) sm[i+1] = a[i]+sm[i];
    REV(i,0,n) {
        mostRecent[sm[i+1]] = i;
        if(mostRecent.find(sm[i]) != mostRecent.end()) {
            fp[i] = mostRecent[sm[i]];
        } else {
            fp[i] = n;
        }
    }
    buildSeg();
    ll ans = 0;
    RE(i,n) {
        ans += getSeg(i,n-1)-i;
    }
    cout<<ans<<endl;
}