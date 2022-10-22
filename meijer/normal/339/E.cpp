#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
int n, a[MX];
ii ans[3];

bool sorted() {
    RE1(i,n) if(a[i] != i) return 0;
    return 1;
}
int findAns(int cur) {
    if(sorted()) return cur;
    if(cur == 3) return -1;
    RE1(i,n) {
        REP(j,i+1,n+1) {
            if(abs(a[i]-a[j+1]) != 1 && abs(a[i-1]-a[j]) != 1)
                continue;
            ans[cur] = {i,j};
            reverse(a+i,a+j+1);
            int ret = findAns(cur+1);
            if(ret != -1) return ret;
            reverse(a+i,a+j+1);
        }
    }
    return -1;
}

void program() {
    cin>>n;
    RE1(i,n) cin>>a[i];
    a[0]=0; a[n+1]=n+1;
    int len = findAns(0);
    cout<<len<<endl;
    REV(i,0,len) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
}