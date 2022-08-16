#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int main()
{
	
	int n;
	scanf("%d", &n);
	vector<int> st;
	set<int> H;
	int cur = 0, ans = 0;
	for (int i = 1; i <= 2*n; ++ i)
	{
		char s[8];
		scanf("%s", s);
		if (s[0] == 'a')
		{
			int x;
			scanf("%d", &x);
			st.push_back(x);
		}
		else
		{
			++ cur;
			if (!st.empty())
			{
				if (st.back() == cur)
					st.pop_back();
				else
				{
					ans ++;
				//	for (auto x : st)
					//	H.insert(x);
					st.clear();
				}
			}
			else
			{
				
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}