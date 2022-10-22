#include <bits/stdc++.h>

using namespace std;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int MX = 1e5, MOD=1e9+7;
int n;
bool r[MX], b[MX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    RE(i,n) cin>>r[i];
    RE(i,n) cin>>b[i];
    int mn=0, cnt=0;
    RE(i,n) {
        if(r[i] && !b[i]) cnt++;
        if(!r[i] && b[i]) mn++;
    }
    if(cnt == 0) cout<<-1<<endl;
    else {
        RE(i,n+2) {
            if(i*cnt > mn) {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}