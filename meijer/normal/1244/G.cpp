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

const int MX=2e6;
ll n, k;
ll ans[MX];
bitset<MX> used;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ll cur=0;
    REP(i,1,n+1) cur += i;
    if(cur > k) {
        cout<<-1<<endl;
        return 0;
    } else {
        used.reset();
        ll big = n;
        REP(i,1,n+1) {
            ans[i] = -1;
            if(cur != k && big > i) {
                if(cur + big-i > k) {
                    big = k - cur + i;
                    cur = k;
                    ans[i] = big;
                    used[big] = 1;
                } else {
                    cur += big - i;
                    ans[i] = big;
                    used[big] = 1;
                    big--;
                }
            }
        }
        int j=1;
        REP(i,1,n+1) {
            if(ans[i] == -1) {
                while(used[j]) j++;
                ans[i] = j++;
            }
        }
        cout<<cur<<endl;
        REP(i,1,n+1)
            cout<<(i==1?"":" ")<<i; cout<<endl;
        REP(i,1,n+1)
            cout<<(i==1?"":" ")<<ans[i]; cout<<endl;
    }
}