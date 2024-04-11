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
int n, k, a[MX];
int SA[MX];
int b[MX];

bool possible(int x) {
    RE(i,n) b[i] = 0;
    RE(i,x) b[SA[i]] = 1;
    
    RE(start,2) {
        bool cur=start;
        int cnt=0;
        RE(i,n) {
            if(b[i] >= cur) cnt++, cur = !cur;
        }
        if(cnt >= k) return 1;
    }
    return 0;
}

void program() {
    cin>>n>>k;
    RE(i,n) cin>>a[i];
    RE(i,n) SA[i]=i;
    sort(SA,SA+n, [](int i, int j) {
        return a[i]<a[j];
    });
    int lb=0, ub=n;
    while(lb != ub) {
        int mid=(lb+ub)/2;
        if(possible(mid)) ub=mid;
        else lb=mid+1;
    }
    cout<<a[SA[lb-1]]<<endl;
}