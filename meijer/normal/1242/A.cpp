#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5, MOD=1e9+7;
ll n, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; y=n;
    vll f;
    for(ll x=2; x*x <= y; x++) {
    	if(y%x == 0) f.pb(x);
    	while(y%x == 0)
    		y /= x;
    }
    if(y > 1) f.pb(y);
    if(f.size() == 1) {
    	cout<<f[0]<<endl;
    } else {
    	cout<<1<<endl;
    }
}