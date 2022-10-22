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

const int MX = 501;
int n;
int a[MX][MX];

void program() {
    cin>>n;
    if(n <= 2) {
        cout<<-1<<endl;
        return;
    }
    if(n == 4) {
        cout<<"4 3 6 12\n7 5 9 15\n14 1 11 10\n13 8 16 2"<<endl;
        return;
    }
    int cur = 1;
    RE(i,n-1) a[i][n-1] = cur++;
    RE(i,n-1) a[n-1][n-i-2] = cur++;
    RE(i,n-2) a[n-i-3][0] = cur++;
    RE(i,n-1) {
        if(i == n-2) a[n-1][n-1] = cur++;
        if(i%2) {
            REV(j,1,n-1) a[i][j] = cur++;
        } else {
            REP(j,1,n-1) a[i][j] = cur++;
        }
    }
    a[n-2][0] = cur++;
    RE(i,n) {
        RE(j,n) cout<<(j==0?"":" ")<<a[j][i];
        cout<<endl;
    }
}