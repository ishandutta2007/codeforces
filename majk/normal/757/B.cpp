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

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

// #include "../l/mod.h"

int F = 100000;

class TaskB {
public:
	void solve(istream& cin, ostream& cout) {
		int N; cin >> N;
		vector<int> S(N); cin >> S;

		vector<vector<int>> D(F+1);
		for(int i = 2; i <= F; ++i) {
			for (int j = i; j <= F; j+=i) {
				D[j].push_back(i);
			}
		}

		vector<int> Q(F+1, 0);
		for (int s: S) {
			Q[s]++;
		}

		vector<int> C(F+1, 0);
		for (int i = 2; i <= F; ++i) {
			if (!Q[i]) continue;
			for (int d: D[i]) {
				C[d] += Q[i];
			}
		}

		int ans = *max_element(C.begin(), C.end());
		ans = max(ans, 1);
		cout << ans << endl;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}