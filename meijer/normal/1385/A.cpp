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
int testCases;
int a[3];

void program() {
    cin>>testCases;
    while(testCases--) {
        RE(i,3) cin>>a[i];
        RE(i,3) RE(j,3) {
            if(i == j) continue;
            if(a[i] == a[j]) {
                RE(k,3) {
                    if(k == i || k == j) continue;
                    int b[3];
                    b[0] = 1;
                    b[1] = a[i];
                    b[2] = a[k];
                    if(a[k] > a[i]) {
                        cout<<(0 ? "YES" : "NO")<<endl;
                        goto stop;
                    }
                    cout<<(1 ? "YES" : "NO")<<endl;
                    RE(_pi,3) cout<<(_pi==0?"":" ")<<b[_pi]; cout<<endl;
                    goto stop;
                }
            }
        }
        cout<<(0 ? "YES" : "NO")<<endl;
        stop:
        int op = 4;
    }
}