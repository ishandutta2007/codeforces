#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;

int arr[maxn][2], n;
int value[maxn];
int type[maxn];
bool change[maxn];

void dfs(int x)
{
	if (!x) return;
	if (type[x] == -1) return;
	dfs(arr[x][0]);
	dfs(arr[x][1]);
	if (type[x] == 0) value[x] = (1 ^ value[arr[x][0]]);
	if (type[x] == 1) value[x] = (value[arr[x][0]] & value[arr[x][1]]);
	if (type[x] == 2) value[x] = (value[arr[x][0]] | value[arr[x][1]]);
	if (type[x] == 3) value[x] = (value[arr[x][0]] ^ value[arr[x][1]]);
}

void result(int x)
{
	if (!x) return;
	if (type[x] == -1)
	{
		change[x] = 1;
		return;
	}
	
	if (type[x] == 0)
	{
		result(arr[x][0]);
		result(arr[x][1]);
	}
	
	if (type[x] == 1)
	{
		if (value[arr[x][0]] == 1 && value[arr[x][1]] == 1)
		{
			result(arr[x][0]);
			result(arr[x][1]);
		}
		else if (value[arr[x][0]] == 0 && value[arr[x][1]] == 1) result(arr[x][0]);
		else if (value[arr[x][0]] == 1 && value[arr[x][1]] == 0) result(arr[x][1]);
	}
	
	if (type[x] == 2)
	{
		if (value[arr[x][0]] == 0 && value[arr[x][1]] == 0)
		{
			result(arr[x][0]);
			result(arr[x][1]);
		}
		else if (value[arr[x][0]] == 1 && value[arr[x][1]] == 0) result(arr[x][0]);
		else if (value[arr[x][0]] == 0 && value[arr[x][1]] == 1) result(arr[x][1]);
	}
	
	if (type[x] == 3) 
	{
		result(arr[x][0]);
		result(arr[x][1]);
	}
	
}

int main()
{
	boost; cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n)
	{
		string s;
		cin >> s;
		if (s == "IN")
		{
			cin >> value[i];
			type[i] = -1;
		}
		else if (s == "NOT") cin >> arr[i][0];
		else cin >> arr[i][0] >> arr[i][1];
		if (s == "AND") type[i] = 1;
		if (s == "XOR") type[i] = 3;
		if (s == "OR") type[i] = 2;
	}
	
	dfs(1);
	result(1);
	FOR(i, 1, n)
		if (type[i] == -1) cout << (value[1] ^ change[i]);
}