#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
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
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
 
// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const vector<T>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class T> void OUT(const vector<T>& x) {RE(i,x.size()) OUT(i==0?"":" ",x[i]);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }
template<class H> void OUTLS(const H& h) {OUTL(h); }
template<class H, class... T> void OUTLS(const H& h, const T&... t) {OUT(h,' '); OUTLS(t...); }
 
//===================//
//  Added libraries  //
//===================//
 
// sparse library
constexpr size_t _LOG2(size_t _X) {return _X < 2 ? 0 : 1 + _LOG2(_X/2);}
int LOG2(int _X) {return _X < 2 ? 0 : 1 + LOG2(_X/2);}

template<size_t SIZE, class T>
class Sparse {
public:
	void build(T values[], int size, function<T(T,T)> func) {
		sz	= size;
		f	= func;
		for(int i=0; i!=sz; i++)
			a[i][0] = values[i];
		for(int j=1; (1<<j)<=sz; j++)
			for(int i=0; i+(1<<j)-1<sz; i++)
				a[i][j] = f(a[i][j-1], a[i+(1<<(j-1))][j-1]);
	}
	T query(int i, int j) {
		if(j < i) swap(i,j);
		int k = LOG2(j-i+1);
		return f(a[i][k], a[j-(1<<k)+1][k]);
	}

private:
	int a[SIZE][_LOG2(SIZE)];
	int sz;
	function<T(T,T)> f;
};

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
int n, a[MX];
int sa[MX];
Sparse<MX,int> st;
int mxK[MX];
int sm[MX];

void program() {
    IN(testCases);
    while(testCases--) {
        IN(n);
        RE(i,n) IN(a[i]);
        st.build(a,n,[](int i, int j){return min(i,j);});

        RE(i,n) sa[i]=i;
        sort(sa,sa+n,[](int i, int j) {
            return a[i]<a[j];
        });

        RE1(i,n) mxK[i]=0;

        RE(x,n) {
            int i=sa[x];
            int beg, end;

            // get begin
            int lb=0,ub=i;
            while(lb!=ub) {
                int mid=(lb+ub)/2;
                if(st.query(mid,i)<a[i]) lb=mid+1;
                else ub=mid;
            }
            beg = lb;

            // get end
            lb=i,ub=n-1;
            while(lb!=ub) {
                int mid=(lb+ub+1)/2;
                if(st.query(i,mid)<a[i]) ub=mid-1;
                else lb=mid;
            }
            end = lb;

            mxK[a[i]]=max(mxK[a[i]],end-beg+1);
        }
        
        RE(i,n+2) sm[i]=0;

        RE1(i,n) {
            int k = mxK[i];
            int lastNeeded = n-i+1;
            sm[min(k,lastNeeded)]++;
            sm[lastNeeded]--;
        }
        RE(i,n+2) sm[i+1]+=sm[i];
        RE(i,n) {
            if(sm[i]) OUT(0);
            else OUT(1);
        }
        OUTL();
    }
}