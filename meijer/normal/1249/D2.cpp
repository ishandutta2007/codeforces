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

const int MX=2e5;
int k, n;
int l[MX], r[MX];
vii e[MX];
int SA[MX];
vi ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n)
        cin>>l[i]>>r[i], l[i]--, r[i]--;
    RE(i,n)
        e[l[i]].pb({r[i],i+1});
    set<ii> q;
    RE(i,MX) {
        while(!q.empty()) {
            auto last = q.begin();
            if(last->first < i) {
                q.erase(last);
            } else {
                break;
            }
        }
        for(ii n : e[i]) {
            q.insert(n);
        }
        while(q.size() > k) {
            auto it = --q.end();
            ans.pb(it->second);
            q.erase(it);
        }
    }
    cout<<ans.size()<<endl;
    RE(i,ans.size())
        cout<<(i==0?"":" ")<<ans[i];
    cout<<endl;
}