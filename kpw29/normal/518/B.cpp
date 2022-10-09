#include <bits/stdc++.h>
#define maxn 200100
#define mp make_pair

using namespace std;
typedef pair <int, int> BONG;
typedef long long ll;
typedef unsigned int ui;
const int mod = 1e9+7;

ll potmod(ll a, ll b)
{
	if (!b) return 1;
	if (b & 1) return a%mod * potmod(a * a, b >> 1) %mod;
	return potmod(a * a, b>>1) %mod;
}

int n,m,a,b,c;
string s1, s2;
string tmp;

bool mniejszy(string a, string b)
{
	int dl = a.length();
	for (int i=0; i<dl; ++i)
	{
	  if (a[i] < b[i]) return true;
	  if (a[i] > b[i]) return false;
  }
	return false;
}

char swap_case(char zn)
{
	int x = zn - 'a';
	char ret;
	if (x < 0) //mamy gore
		ret = zn - 'A' + 'a';
	else ret = zn - 'a' + 'A';
	return ret;
	
}

map <char, int> ile;
bool wyk[maxn];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	int yay=0, whoops=0;
	for (int i=0; i<m; ++i)
	{
		ile[s2[i]]++;
	}
	
	for (int i=0; i<n; ++i)
	{
		char x = s1[i];
		if (ile[x]) ++yay, --ile[x], wyk[i] = true;
	}
	
	for (int i=0; i<n; ++i)
	{
		if (wyk[i]) continue;
		char zn = swap_case(s1[i]);
		if (ile[zn]) ++whoops, --ile[zn];
	}
	printf("%d %d", yay, whoops);

	
	
	return 0;
}