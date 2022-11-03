#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , b[maxn] , num[maxn];

vector<int> pos[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n , m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int sum = 0;
	for(int i = 1; i <= m; i++)
		cin >> b[i] , sum += b[i];

	multiset<int> st;

	for(int i = 1; i <= m; i++)
	{
		if(!b[i])
			st.insert(n) , num[i] = n;
		else
			st.insert(0) , num[i] = 0;
	}

	int res = 1e7;

	for(int i = 1; i <= n; i++)
	{
		pos[a[i]].pb(i);

		if((int)pos[a[i]].size() < b[a[i]])
			continue;
		else if(b[a[i]] != 0)
		{
			st.erase(st.find(num[a[i]]));

			int tmp = pos[a[i]].size();

			num[a[i]] = pos[a[i]][tmp - b[a[i]]];
			st.insert(num[a[i]]);
		}

		if(*st.begin() != 0)
			res = min(res , i - *st.begin() + 1);
	}

	if(res > n)
		res = -1;
	else
		res -= sum;

	cout << res << endl;

}