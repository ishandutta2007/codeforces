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

const int MX = 5e5;
int n, k, m[MX], c[MX];
int cntTC[MX];
vi ans[MX];

bool possible(int TC) {
    RE(i,TC) cntTC[i] = 0;
    int cur=0;
    RE(i,n) {
        cntTC[cur]++;
        if(cntTC[cur] > c[m[i]]) {
            return 0;
        }
        cur = (cur+1)%TC;
    }
    return 1;
}
void fillAns(int TC) {
    int cur=0;
    RE(i,n) {
        ans[cur].pb(m[i]);
        cur = (cur+1)%TC;
    }
}

void program() {
    cin>>n>>k;
    RE(i,n) cin>>m[i];
    RE1(i,k) cin>>c[i];
    sort(m, m+n, greater<int>());
    int lb=1, ub=n;
    while(lb != ub) {
        int mid = (lb+ub)/2;
        if(possible(mid)) ub = mid;
        else lb = mid+1;
    }
    fillAns(lb);
    cout<<lb<<endl;
    RE(i,lb) {
        cout<<ans[i].size();
        RE(j,ans[i].size()) cout<<" "<<ans[i][j];
        cout<<endl;
    }
}