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
#define X real()
#define Y imag() 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef complex<LD> P;
typedef pair<int, int> PII;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }

PII conv(P x){return MP((int)roundl(x.X),(int)roundl(x.Y));}

set<PII> S;
int n;
vector<P> v;
LD res = 0.0;

bool vis(P p, LD t) {
    REP(i,n) if(norm(p-v[i]) < t)
        return false;
    return true;
}

inline LD operator^(const P& a,const P& b){return real(a)*imag(b)-imag(a)*real(b);}//iloczyn wektorowy
inline LD operator%(const P& a,const P& b){return real(a)*real(b)+imag(a)*imag(b);}//iloczyn skalarny
inline LD wek(const P& a,const P& b,const P& c){return (b-a)^(c-a);}
#define EPS 1E-10

int prosta_prosta(const P& A,const P& B,const P& C,const P& D,P& p){//-1 - proste sie pokrywaja
    if(abs((A-B)^(C-D))<EPS)//AB || CD
        return (abs(wek(A,B,C))<EPS?-1:0);
    LD a=(wek(C,D,A)),b=(A-B)^(C-D);
    p=(B*a+A*(b-a))/b;
    return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n;
    REP(i,n) {
        int x,y;
        cin >> x >> y;
        x *= 2; y *= 2;
        v.PB(P(x,y));
        S.insert(conv(v.back()));
    }
	//sol
    REP(i,n) REP(j,i) REP(k,n) if(k != i && k != j){
        P s = 0.5l * (v[i] + v[j]);
        LD t = norm(s-v[i]);
        if(t == norm(s-v[k]) && S.count(conv(s+(s-v[k]))) && vis(s,t))
            maxi(res, t);
    }
    REP(i,n) REP(j,n) REP(k,n) {
        vector<LD> d;
        d.PB(norm(v[i]-v[j]));
        d.PB(norm(v[i]-v[k]));
        d.PB(norm(v[k]-v[j]));
        sort(ALL(d));
        if(d[0]+d[1] > d[2]+EPS) {
            P s,s1=0.5l*(v[i]+v[j]),s2=0.5l*(v[j]+v[k]);
            prosta_prosta(s1, s1+P(0,1)*(v[j]-s1), s2, s2+P(0,1)*(v[j]-s2), s);
            LD t = norm(s-v[i]);
            if(vis(s,t))
                maxi(res,t);
        }
    }
	//out
    if(res == 0.0){cout << -1 << endl; return 0;}
    cout << fixed << setprecision(9) << sqrtl(res)/2.0l << endl;
	return 0;
}