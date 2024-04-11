#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll INF = 1e18+3;
#define maxn 1000100
int klucze[30];
char t[maxn];
int zamiast[maxn];
char wyn[maxn];
int main()
{
string s;
	cin >> s;
	for (int i=0; i<s.length(); ++i) t[i+1] = s[i];
	int m, a, b;
	cin >> m;
	int n = s.length();
	int pol = (n+1)/2;
	while (m--)
	{
		cin >> a;
		if (a > pol) a = n - a + 1;
		zamiast[a]++;
	}
	int ost = 0;
	for (int i=1; i<=pol; ++i)
	{
		ost = (ost + zamiast[i])%2;
		if (ost == 1)
		{
			wyn[i] = t[n-i+1];
			wyn[n-i+1] = t[i];
		}
		else
		{
			wyn[i] = t[i];
			wyn[n-i+1] = t[n-i+1];
		}
	}
	for (int i=1; i<=n; ++i) printf("%c", wyn[i]);
}