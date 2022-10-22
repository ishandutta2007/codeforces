
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
  
using namespace std;
  
#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 
  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
  
const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

int mex(vec< int > a) {
	sort(ALL(a));
	a.resize(unique(ALL(a)) - a.begin());
	if(a.empty()) return 0;
	if(a[0] > 0) return 0;
	if((int)a.size() - 1 == a.back()) return (int)a.size();
	for(int i = 0;i + 1 < (int)a.size();i++) {
		if(a[i] + 1 < a[i + 1]) return a[i] + 1;
	}
}

int g(int n, int k) {
	if(k % 2 == 0) {
		if(n <= 2) return n;
		else return (n % 2?0 : 1);
	}else {
		if(n <= 3) return (n == 0 || n == 2?0 : 1);
		else {
			if(n % 2) return 0;
			vec< int > tmp;
			tmp.push_back(g(n - 1, k));
			tmp.push_back(k % 2?g(n / 2, k) : 0);
			return mex(tmp);
		}
	}
}

bool solve() {
  
	int n, k, ans = 0;

	scanf("%d %d", &n, &k);

	for(int x, i = 0;i < n;i++) scanf("%d", &x), ans ^= g(x, k);

	puts(ans?"Kevin" : "Nicky");

    return true;
}
  
int main() {
      
	//while(solve());
    solve();    
  
    return 0;
}