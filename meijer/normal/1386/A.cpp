
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
ll testCases;
ll n, last;
bool curDir = 0;
stack<ll> stck;
 
bool ask(ll x) {
  cout<<"? "<<x<<endl;
  cout<<endl;
  bool res; cin>>res;
  last = x;
  return res;
}
bool askChange(ll y) {
    curDir = !curDir;
    if(curDir) last += y;
    else last -= y;
    return ask(last);
}
 
void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
 
        ll lb=1, ub=n;
        while(lb != ub) {
            ll mid=(lb+ub-1)/2;
            lb = mid+1;
            stck.push(mid);
        }
        ll x = 1;
        bool dir = 1;
        while(!stck.empty()) {
            ll u = stck.top(); stck.pop();
            if(dir) x += u;
            else x -= u;
            dir = !dir;
        }
        curDir = !dir;
        ask(x);
 
        lb=1, ub=n;
        while(lb != ub) {
            ll mid=(lb+ub-1)/2;
            if(askChange(mid)) ub = mid;
            else lb = mid+1;
        }
        
        cout<<"= "<<lb<<endl;
        cout<<endl;
    }
}