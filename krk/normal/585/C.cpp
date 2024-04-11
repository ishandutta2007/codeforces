#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, char> llc;

ll x, y;
vector <llc> V;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

void solveGCD(ll x, ll y, char a, char b)
{
	if (x == 1) {
		if (y > 1) V.push_back(llc(y - 1, b));
		return;
	}
	if (x < y) V.push_back(llc(y / x, b));
	solveGCD(y % x, x, b, a);
}

int main()
{
	scanf("%I64d %I64d", &x, &y);
	if (gcd(x, y) != 1) printf("Impossible\n");
	else {
		solveGCD(x, y, 'A', 'B');
		for (int i = 0; i < V.size(); i++)
			printf("%I64d%c", V[i].first, V[i].second);
		printf("\n");
	} 
}