#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 1500100

const long double T = 1.000000011;
ll a1, a2, b1, b2;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double delta = (b * b - 4 * a * c);
	double x1 = (-b + sqrt(delta))/(2*a);
	double x2 = (-b - sqrt(delta))/(2*a);
	printf("%.9lf\n%.9lf", max(x1, x2), min(x1, x2));
}