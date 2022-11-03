#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int f[maxn] , l[maxn] , o;
int main()
{
	int n , k;
	string s;
	cin >> n >> k >> s;
	fill(f , f + maxn , maxn);
	for(int i = 0; i < n; i++)
	{
		f[s[i] - 'A'] = min(f[s[i] - 'A'] , i);
		l[s[i] - 'A'] = max(l[s[i] - 'A'] , i);
	}
	for(int i = 0; i < n; i++)
	{
		if(f[s[i] - 'A'] == i)
			o++;
		if(o > k)
		{
			cout << "YES\n";
			return 0;
		}
		if(l[s[i] - 'A'] == i)
			o--;
	}
	cout << "NO\n";
	return 0;
}