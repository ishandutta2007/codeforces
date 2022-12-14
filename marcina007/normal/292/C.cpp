#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007
#define LIM 256

int ok,use[LIM],len[LIM],m;
string val[LIM];
vector<string> ans;
VI act;
int comp[LIM];
char text[LIM];
int dl;

void go(int n) {
    if(dl + (4-n) > m) return;
    if(dl + (4-n)*3 < m) return;
//    if(n==4) {cout << n << ": "; FORE(i,act) cout << *i << " "; cout << endl;}
    if(n == 4) {
        int u = 0;
        FORE(i,act)
            u |= use[*i];
        if(u != ok) return;
        string s;
        FORE(i,act)
            s += "." + val[*i];
        ans.PB(s.substr(1,-1));
        return;
    }
    REP(i,LIM) if((use[i]|ok) == ok){
        REP(j, len[i])
            text[dl+j] = val[i][j];
        bool tak = true;
        REP(j, len[i])
            if(comp[dl+j] != -1 && text[dl+j] != text[comp[dl+j]])
                tak = false;
        if(tak) {
            act.PB(i);
            dl += len[i];
            go(n+1);
            dl -= len[i];
            act.pop_back();
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    int n;
    cin >> n;
    if(n>6) {cout << 0 << endl; return 0;}
    while(n--) {
        int x;
        cin >> x;
        ok |= (1 << x);
    }
	//sol
    REP(i,LIM) {
        stringstream ss;
        ss << i;
        ss >> val[i];
        FORE(j,val[i])
            use[i] |= (1 << (*j-'0'));
        len[i] = SZ(val[i]);
    }
//    REP(i,20) cout << i << " " << val[i] << " " << len[i] << " " << use[i] << "      " << ok << " " << (use[i]|ok) << endl;
    for(m=4; m<=12; m++) {
        REP(i,m)
            if(m-1-i < i)
                comp[i] = m-1-i;
            else
                comp[i] = -1;
        go(0);
    }
	//out
    cout << SZ(ans) << endl;
    FORE(i,ans)
        cout << *i << endl;
	return 0;
}