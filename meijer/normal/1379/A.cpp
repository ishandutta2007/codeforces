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
int n, m;
string s;
string t;
string T = "abacaba";

int compare(int i) {
    if(i+m > n) return 0;
    RE(j,m) if(t[i+j] != T[j]) return 0;
    return 1;
}
bool tryI(int i) {
    if(i+m > n) return 0;
    t = s;
    RE(j,n) if(t[j] == '?') t[j] = 'z';
    RE(j,m) if(s[i+j] == '?') t[i+j] = T[j];
    int cnt=0;
    RE(i,n) cnt += compare(i);
    return cnt==1;
}

void program() {
    cin>>testCases;
    m = T.sz;
    while(testCases--) {
        cin>>n>>s;
        bool pos=0;
        RE(i,n) {
            if(tryI(i)) {
                pos=1;
                break;
            }
        }
        cout<<(pos ? "Yes" : "No")<<endl;
        if(pos) cout<<t<<endl;
    }
}