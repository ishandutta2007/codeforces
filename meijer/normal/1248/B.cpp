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
#define fi first
#define se second

const int MX=1e5;
int n, a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    sort(a,a+n);
    ll small = n/2;
    ll x,y;
    x=y=0;
    RE(i,small)
    	x += a[i];
    REP(i,small,n)
    	y += a[i];
    cout<<(x*x+y*y)<<endl;
}