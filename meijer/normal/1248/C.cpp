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

const ll MX=1e5, MOD=1e9+7;
ll n, m;
ll mem[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    mem[0] = 1;
    mem[1] = 1;
    REP(i,2,max(n,m)+1) mem[i] = (mem[i-1]+mem[i-2])%MOD;
    cout<<((mem[n]+mem[m]-1+MOD)*2)%MOD<<endl;
}