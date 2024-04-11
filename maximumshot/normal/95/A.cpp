#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
	os.precision(10);
	os << fixed;
	os << a.first;
	os << ' ';
	os << a.second;
	os << ' ';
	return os;
}

string read() {
	char buffer[110];
	scanf("%s", &buffer);
	return buffer;
}

bool solve()
{
	int n;

	scanf("%d", &n);

	vec<string> a(n);

	string s;
	char LuckySymbol;

	for(int i(0);i < n;i++) {
		a[i] = read();
	}

	s = read();
	scanf(" %c", &LuckySymbol);

	int MainSize = (int)s.size();

	vec<bool> can(MainSize, 0);

	for(int i(0);i < n;i++) {
		int nowSize = (int)a[i].size();

		for(int j(0);j + nowSize - 1 < MainSize;j++) {

			bool ok = 1;

			for(int index(0), q(j);q <= j + nowSize - 1;q++, index++) {
				int c1, c2;
				c1 = a[i][index]; c2 = s[q];
				if(c1 >= 'A' && c1 <= 'Z') c1 = c1 - 'A' + 'a';
				if(c2 >= 'A' && c2 <= 'Z') c2 = c2 - 'A' + 'a';
				ok &= (c1 == c2);
			}

			if(ok) {
				for(int q(j);q <= j + nowSize - 1;q++) {
					can[q] = 1;
				}
			}
		}
	}

	for(int i(0);i < MainSize;i++) {
		if(!can[i]) continue;
		bool isBig = 0;
		if(s[i] >= 'A' && s[i] <= 'Z') {
			isBig = 1;
			s[i] = s[i] - 'A' + 'a';
		}

		if(s[i] == LuckySymbol) {
			if(LuckySymbol == 'a') {
				s[i] = 'b';
			}else {
				s[i] = 'a';
			}
		}else {
			s[i] = LuckySymbol;
		}
		
		if(isBig) {
			s[i] = s[i] - 'a' + 'A';
		}
	}

	cout << s << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();
	
	return 0;
}