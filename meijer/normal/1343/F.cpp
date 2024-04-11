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

const int MX = 210;
int t, n, k[MX], a[MX][MX];
set<int> inA[MX];
vi ans;
set<set<int>> sts;

bool findAns2(int BEG) {
    ans.clear();
    RE(i,n-1) inA[i].clear();
    RE(i,n-1) RE(j,k[i]) inA[i].insert(a[i][j]);
    queue<int> nxt; nxt.push(BEG);
    while(!nxt.empty()) {
        int u = nxt.front(); nxt.pop();
        ans.pb(u);
        RE(i,n-1) {
            if(inA[i].size() == 1) continue;
            inA[i].erase(u);
            if(inA[i].size() == 1) nxt.push(*inA[i].begin());
        }
    }
    if(ans.size() != n) return 0;
    REP(i,1,n) {
        bool found = 0;
        set<int> cs; cs.insert(ans[i]);
        REV(j,0,i) {
            cs.insert(ans[j]);
            if(sts.count(cs)) {
                found = 1;
                break;
            }
        }
        if(!found) return 0;
    }
    return 1;
}

void program() {
    cin>>t;
    while(t--) {
        cin>>n;
        sts.clear();
        RE(i,n-1) {
            cin>>k[i];
            RE(j,k[i]) cin>>a[i][j];
            set<int> cs;
            RE(j,k[i]) cs.insert(a[i][j]);
            sts.insert(cs);
        }
        RE1(i,n) {
            if(findAns2(i)) break;
        }
        RE(i,ans.size()) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
    }
}