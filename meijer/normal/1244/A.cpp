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
int t, a, b, c, d, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d>>k;
        int ans=-1;
        RE(i,k+1) {
            int acnt = c*i;
            int bcnt = d*(k-i);
            if(acnt >= a && bcnt >= b) {
                ans = i;
                break;
            }
        }
        if(ans == -1) cout<<ans<<endl;
        else cout<<ans<<" "<<(k-ans)<<endl;
    }
}