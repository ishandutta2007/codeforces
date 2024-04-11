#include <bits/stdc++.h>
#define maxn 110
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
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s1 >> s2;
	n = s1.length();
	tmp  = s1;
	bool czy = false;
	for (int i=0; i<n; ++i) if (s1[i] != 'z') czy = true;
	if (!czy) puts("No such string");
	else
	{
		for (int i=n-1; i>=0; --i)
		  if (s1[i] == 'z') continue;
		  else 
		  {
			  int x = s1[i];
			  ++x;
			  tmp[i] = x;
			  for (int j=i+1; j<n; ++j) tmp[j] = 'a';
			  break;
		  }
		if (mniejszy(tmp, s2)) cout << tmp;
		else cout << "No such string";
	}
	
	return 0;
}