#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

#define MOD 1000000007
#define INF MOD

set <int> l, g, un;


int n;
LL an = 1;
char s[10005];

int main() {
	read(n);
	l.insert(-INF);
	g.insert(INF);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%s", s);
		read(x);
		if (s[1] == 'D') {
				 if (*l.rbegin() >= x) l.insert(x);
			else if (*g.begin() <= x) g.insert(x);
			else un.insert(x);
		}
		else {
				 if (*l.rbegin() == x) l.erase(x);
		//	else if (*l.rbegin() > x) return puts("0"), 0;
			else if (*g.begin() == x) g.erase(x);
		//	else if (*g.begin() < x) return puts("0"), 0;
			else if (x > *l.rbegin() && x < *g.begin() && un.find(x) != un.end()) {
							an = an * 2 % MOD;
			} else {
				 puts("0");
				 return 0;
			 }
			for (auto v : un) {
					if (v < x) l.insert(v);
					if (v > x) g.insert(v);
				}
				un.clear();
	
		}
	}
	an = an * int(un.size() + 1) % MOD; 
	cout << int(an) << endl;;
	return 0;
}