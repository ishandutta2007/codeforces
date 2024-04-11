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

const int MX=6000;
ll t, n, m[MX], p[MX];
ll mem[MX][MX], SA[MX];

ll getAns(ll r, ll i) {
    if(r < 0) return 0;
    if(mem[r][i] == -1) {
        if(m[SA[r]] > r + i) {
            mem[r][i] = p[SA[r]]+getAns(r-1, i+1);
        } else {
            mem[r][i] = min(getAns(r-1,i), p[SA[r]]+getAns(r-1,i+1));
        }
    }
    return mem[r][i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n;
        RE(i,n) cin>>m[i]>>p[i];
        RE(i,n) SA[i]=i;
        sort(SA, SA+n, [](int i, int j) {
            return m[i]<m[j];
        });
        RE(i,n+1) RE(j,n+1) mem[i][j]=-1;
        cout<<getAns(n-1,0)<<endl;
    }
}