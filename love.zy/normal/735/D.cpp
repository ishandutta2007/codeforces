#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
bool pd(int n)
{
	int t = (int)sqrt((double)n) + 1;
	for (int i = 2; i <= t; i++)
		if (n % i == 0)
			return false;
	return true;
}

int n;

int main()
{
	scanf("%d",&n);
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 4) {
		cout << 2 << endl;
		return 0;
	}
	if (n == 5) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 6) {
		cout << 2 << endl;
		return 0;
	}
	if (n % 2 == 0) {
		cout << 2 << endl;
	} else {
		if (pd(n)) {
			cout << 1 << endl;
		} else {
			if (pd(n - 2))
				cout << 2 << endl;
			else
				cout << 3 << endl;
		}
	}
	return 0;
}