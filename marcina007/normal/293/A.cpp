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
#include<bitset>
#include<stack>
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
#define MAXN 2000007

int n;
string a[2];
bool vis[MAXN];
vector<P> A[2];
int score[2];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> a[0] >> a[1];
    n *= 2;
	//sol
    REP(j,2) REP(i,n) A[j].PB(P((a[j][i]-'0')*10+(a[1-j][i]-'0'), i));
    REP(j,2) sort(ALL(A[j]));
	//out
    REP(i,n) {
        int p=i%2;
        while(vis[A[p].back().Y]) A[p].pop_back();
        int x= A[p].back().Y; A[p].pop_back();
//        cout << x << endl;
        vis[x] = true;
        score[p] += a[p][x] - '0';
//        cout << p << " " << a[p][x] << " " << score[p] << endl;
    }
    if(score[0] == score[1]) cout << "Draw" << endl;
    if(score[0] > score[1]) cout << "First" << endl;
    if(score[1] > score[0]) cout << "Second" << endl;
	return 0;
}