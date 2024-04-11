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

const int MX = 2e3;
int testCases;
int n, k, c[MX], s[MX][MX];
int ans[MX];

int ask(set<int> s) {
    cout<<"?";
    cout<<" "<<s.size();
    for(int i:s) cout<<" "<<i;
    cout<<endl;
    cout.flush();
    int res; cin>>res;
    return res;
}
int ask(int x, int y) {
    set<int> s;
    REI(i,x,y) s.insert(i);
    return ask(s);
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>k;
        RE(i,k) {
            cin>>c[i];
            RE(j,c[i]) cin>>s[i][j];
        }
        int mx = ask(1,n);
        int lb=1,ub=n;
        while(lb != ub) {
            int mid=(lb+ub)/2;
            if(ask(lb,mid) == mx) ub = mid;
            else lb = mid+1;
        }
        RE(i,k) {
            set<int> st;
            RE(j,c[i]) {
                st.insert(s[i][j]);
            }
            if(st.count(lb)) {
                set<int> ns;
                REI(i,1,n) if(!st.count(i)) ns.insert(i);
                ans[i] = ask(ns);
            } else {
                ans[i] = mx;
            }
        }
        cout<<"!";
        RE(i,k) cout<<" "<<ans[i];
        cout<<endl;
        cout.flush();
        std::string res;
        cin>>res;
        if(res == "Incorrect") return;
    }
}