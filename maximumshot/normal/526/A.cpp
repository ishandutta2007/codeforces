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

bool solve()
{
	int n;
	cin >> n;
	string a;
	cin >> a;

	for(int i(0);i < n;i++) {
		for(int j(1);j < n;j++) {
			int c = 0;
			for(int z(i);z < n && a[z] == '*';z += j) c++;
			if(c >= 5) {
				puts("yes");
				return true;
			}
		}
	}

	puts("no");

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}