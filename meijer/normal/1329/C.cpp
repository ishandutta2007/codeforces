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

const int MX = 2e6;
int t, h, g, n, m, a[MX], depth[MX], ans[MX], curAns=0;

void fillDepth(int p=1, int d=1) {
    if(p > n) return;
    depth[p] = d;
    fillDepth(p*2,d+1);
    fillDepth(p*2+1,d+1);
}
bool canRemove(int p=1) {
    int l=p*2;
    int r=p*2+1;
    if(depth[p] == h || (a[l] == 0 && a[r] == 0)) {
        return depth[p] > g;
    } else {
        if(a[l] > a[r]) {
            return canRemove(l);
        } else {
            return canRemove(r);
        }
    }
}
void remove(int p=1) {
    int l=p*2;
    int r=p*2+1;
    if(depth[p] == h || (a[l] == 0 && a[r] == 0)) {
        a[p] = 0;
    } else {
        if(a[l] > a[r]) {
            a[p] = a[l];
            remove(l);
        } else {
            a[p] = a[r];
            remove(r);
        }
    }
}

void program() {
    cin>>t;
    while(t--) {
        cin>>h>>g;
        n = (1<<h)-1;
        m = (1<<g)-1;
        RE1(i,n) cin>>a[i];
        fillDepth();
        curAns=0;
        queue<int> q; q.push(1);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            while(canRemove(u)) {
                remove(u);
                ans[curAns++] = u;
            }
            if(depth[u] != g) {
                q.push(2*u);
                q.push(2*u+1);
            }
        }
        ll tot=0;
        RE1(i,m) tot += a[i];
        cout<<tot<<endl;
        RE(i,curAns) cout<<(i==0?"":" ")<<ans[i];
        cout<<endl;
    }
}