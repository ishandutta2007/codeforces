#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
using namespace std;
vector<int> v;
const int N= 3e5 + 5;
string s[N];
int a[N],b[N];
bool cmp(int x,int y)
{
	return a[x] * b[y] > a[y] * b[x];
}
signed main()
{
	int n; cin >> n;
	for(int i = 0;i < n; ++i)
	{
		cin >> s[i];
		a[i] = b[i] = 0;
		for(char c: s[i])
		{
			if(c == 's') ++a[i];
			else ++b[i];
		}
		v.pb(i);	
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0,ss = 0;
	for(int i: v)
	{
		for(char c: s[i])
		{
			if(c == 's') ++ss;
			else ans += ss;
		}
	}
	
	cout << ans << endl;
}