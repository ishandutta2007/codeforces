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
typedef double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

namespace FFT{

typedef double C;
typedef complex<C> Z;
vector<Z> a,y,tmp;
void DFT(int n,bool rev=false,int p=0,int s=1,int q=0){
	//cout << "DFT " << n << " " << rev << "  "<< p << " " << s << " " << q << endl;
	if(n == 1){y[q]=a[p]; return;}
    Z en=exp(Z(0,2*M_PI/n*(rev?-1:1))),e=1;
	DFT(n/2,rev,p,2*s,q);
	DFT(n/2,rev,p+s,2*s,q+n/2);
	REP(k,n/2){
		tmp[k]=y[q+k]+e*y[q+k+n/2];
		tmp[k+n/2]=y[q+k]-e*y[q+k+n/2];
		e*=en;
	}
	REP(k,n) y[q+k]=tmp[k];
}
vector<Z> DFT(vector<Z> v,bool rev=false){
	REP(i,siz(v)) a[i]=v[i];
	DFT(siz(v),rev);
	REP(i,siz(v)) v[i]=y[i];
	return v;
}
vector<C> sqr(vector<C> va){
	int n=1;
	while((1 << n)<siz(va)) n++; n++;
	n=(1 << n);
	va.resize(n,0);
	a.resize(n,0);
	tmp.resize(n,0);
    y.resize(n,0);
	vector<Z> aa=DFT(vector<Z>(ALL(va)));
	REP(i,n) aa[i]*=aa[i];
	aa=DFT(aa,true);
	vector<C> res(n);
	REP(i,n) res[i]=real(aa[i])/n;
	return res;
}

vector<LL> sqr(vector<LL> v) {
    vector<C> v2(ALL(v));
    v2 = sqr(v2);
    v.resize(siz(v2));
    REP(i,siz(v))
        v[i] = llround(v2[i]);
    return v;
}

}

int n,m;
bool bag[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    while(n--){
        int x;
        cin >> x;
        bag[x] = true;
    }
	//sol
    vector<LL> bags;
    REP(i,m+1) bags.PB(bag[i]);
    bags[0] = 1;
    //debugv(bags);
    bags = FFT::sqr(bags);
    bags.resize(m+1);
    //debugv(bags);
	//out
    FOR(i,1,m) if(bags[i] && !bag[i]) {cout << "NO" << endl; return 0;}
    vector<int> res;
    FOR(i,1,m) if(bags[i] == 2)
        res.PB(i);
    cout << "YES" << endl;
    cout << SZ(res) << endl;
    FORE(i,res) cout << *i << " ";
    cout << endl;
	return 0;
}