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
#include <list>

//#include <conio.h>

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
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
	os.precision(10);
	os << fixed;
	os << "{";
	os << a.first;
	os << ' ';
	os << a.second;
	os << "} "; 
	return os;
}

bool solve()
{	
	int n, k, m;

	scanf("%d %d", &n, &k);

	LL ans = 0;

	vec< pair<int, int> > mas;

	for(int i(0);i < k;i++) {
		scanf("%d", &m);
		vec< int > a(m);
		for(int j(0);j < m;j++) scanf("%d", &a[j]);
		int pos = 0;
		while(pos + 1 < m && a[pos] + 1 == a[pos + 1]) pos++;
		// [0 .. pos]
		ans += m - (pos + 1);
		mas.push_back(mp(a[0], a[pos]));
		for(int j(pos + 1);j < m;j++) mas.push_back(mp(a[j], a[j]));
	}

	sort(ALL(mas));

	for(int i(0);i + 1 < (int)mas.size();i++) {
		ans += mas[i + 1].second - mas[i + 1].first;
		ans += mas[i + 1].second - mas[i + 1].first + 1;
	}
	
	cout << ans << '\n';

	return true;
}   

int main() 
{
	//while(solve());
	solve();

	return 0;
}