/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Majk
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;
typedef unsigned int ui;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;

int logceil(ll x) {int b=0;while(x){x>>=1;++b;}return b;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector<vector<T>>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector<vector<T>>>(a,vector<vector<T>>(b,vector<T>(c,t))){}};
auto polar = [](pii&a,pii&b) {
    if (a.y==0&&a.x>0) return true;
	if (b.y==0&&b.x>0) return false;
	if (a.y>0&&b.y<0) return true;
	return !(a.y<0&&b.y>0) && ((ll)a.x*b.y-(ll)a.y*b.x)>0;
};
typedef pair<ll,ll> pll;

ll ccw(const pll&a, const pll&b, const pll&c) { return (ll)(b.x-a.x)*(c.y-a.y) - (ll)(b.y-a.y)*(c.x-a.x); }
ll area(const pll&a,const pll&b,const pll&c) { return abs(ccw(a,b,c)); }
//
//vector<pii> convexhull(const vector<pii> &v) {
//    int N = v.size(); vector<pii> w(N+1); int lo = 0;
//    for (int i = 0; i<N; ++i) if (v[i].y < v[lo].y) lo = i;
//    pii o = v[lo];
//    for (int i = 0; i<N; ++i) w[i+1] = v[i]-o;
//    swap(w[1],w[lo+1]);
//    sort(w.begin()+2,w.end(),polar);
//    w[0] = w[N];
//    int M=1;
//    for (int i=2;i<=N;++i) {
//        while(ccw(w[M-1],w[M],w[i]) <= 0) if (M>1) --M; else if (i == N) break; else ++i;
//        ++M;
//        swap(w[M],w[i]);
//    }
//    vector<pii> res(M);
//    for (int i=0;i<M;++i) res[i] = w[i+1]+o;
//    return res;
//}



class TaskB {
public:
    void solve(istream& cin, ostream& cout) {
		int N;
		cin >> N;
		vector<pll> X(N);
		for (int i = 0; i < N; ++i) {
			cin >> X[i].x >> X[i].y;
		}

		double ans = 1e12;
		for (int j = 0; j < N; ++j) {
			pll x = X[j];
			pll y = X[(j+2)%N];
			pll z = X[(j+1)%N];
			double cur = area(x, y, z);
			double dist = sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
			if (cur < 1e-9) ans = 0.0;
			else ans = min(ans, cur / dist / 2);
		}

		cout << fixed << setprecision(10) << ans << endl;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}