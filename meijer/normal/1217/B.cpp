#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=200;

ll t, n, x, mxd;
ll d[MX], h[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>x;
        REP(i,0,n) cin>>d[i]>>h[i];
        mxd=d[0];
        REP(i,0,n) mxd=max(mxd, d[i]);
        if(mxd >= x) {cout<<1<<endl; continue;}
        ll bestBlow=-INF;
        REP(i,0,n) bestBlow=max(bestBlow, d[i]-h[i]);
        if(bestBlow <= 0) {cout<<-1<<endl; continue;}
        ll ans = (x-mxd)/bestBlow;
        if((x-mxd)%bestBlow != 0) ans++;
        cout<<ans+1<<endl;
    }
}