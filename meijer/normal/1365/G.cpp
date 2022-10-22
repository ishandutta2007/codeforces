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

const int MX = 5e5;
ll n;

void program() {
    cin>>n;
    vll numbers;
    {
        ll i = 0;
        while(numbers.size() < n) {
            if(__builtin_popcount(i) == 6) numbers.push_back(i);
            i++;
        }
    }
    set<ll> ask[13];
    ll resp[13];
    RE(i,13) {
        RE(j,numbers.sz) {
            if(numbers[j] & (1<<i))
                ask[i].insert(j+1);
        }
        if(ask[i].sz == 0) {
            resp[i] = 0;
            continue;
        }
        cout<<"? "<<ask[i].sz;
        for(ll j:ask[i]) cout<<" "<<j;
        cout<<endl;
        cout.flush();
        cin>>resp[i];
    }
    cout<<"!";
    RE1(i,n) {
        ll ans = 0;
        RE(j,13) if(!ask[j].count(i)) ans |= resp[j];
        cout<<" "<<ans;
    }
    cout<<endl;
}