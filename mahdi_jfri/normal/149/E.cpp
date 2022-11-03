#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

int res , pmx[maxn] , smx[maxn] , f[maxn];

string s , t;

void shit()
{
	int n = s.size() , m = t.size();

	for(int i = 1; i < m; i++)
	{
		int state = f[i];
		while(state && t[state] != t[i])
			state = f[state];
		if(t[state] == t[i])
			state++;
		f[i + 1] = state;
	}
	
	int state = 0;
	for(int i = 0; i < n; i++)
	{
		while(state && t[state] != s[i])
			state = f[state];
		if(t[state] == s[i])
			state++;
		pmx[i + 1] = max(pmx[i] , state);
		if(state == m)
			state = f[state];
	}
}

int main()
{
	int n , q;
	cin >> s >> q;

	n = s.size();

	while(q--)
	{
		cin >> t;
		if(t.size() == 1)
			continue;
		
		shit();
		reverse(s.begin() , s.end());
		reverse(t.begin() , t.end());
		swap(pmx , smx);
		shit();
	
		reverse(s.begin() , s.end());
		for(int i = 1; i <= n; i++)
			if(pmx[i] + smx[n - i] >= (int)t.size())
			{
				res++;
				break;
			}
	}
	cout << res << endl;
}