#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const ll mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[2] = {1000 * 1000 + 6 , 1000 * 100 + 53};

ll h[maxn][2] , a[maxn] , b[maxn] , pw[maxn][2] , c[maxn];

vector<int> v[maxn];

bool mark[maxn];

set<pair<int , int> > st;

ll get(int l , int r , int k)
{
	return (h[r][k] - ((h[l][k] * pw[r - l][k]) % mod[k]) + mod[k]) % mod[k];
}

void prepare(int n)
{
	pw[0][0] = pw[0][1] = 1;
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
			pw[i][j] = (pw[i - 1][j] * base[j]) % mod[j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 2; j++)
			h[i + 1][j] = (h[i][j] * base[j] + c[i]) % mod[j];
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , b[i] = a[i];
	sort(b , b + n);
	for(int i = 0; i < n; i++)
		c[i] = lower_bound(b , b + n , a[i]) - b , v[c[i]].pb(i);
	
	prepare(n);

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < (int)v[i].size(); j++)
			for(int k = j + 1; k < (int)v[i].size(); k++)
			{
				int x = v[i][j] , y = v[i][k];
				bool f = 1;
				for(int l = 0; l < 2; l++)
					if(y + (y - x) > n || get(x , y , l) != get(y , y + (y - x) , l))
						f = 0;
				if(f)
					st.insert({y - x , x});
			}
	while(!st.empty())
	{
		pair<int , int> e = *st.begin();
		st.erase(st.begin());
		if(mark[e.second])
			continue;
		for(int i = e.second + e.first - 1; i >= 0 && !mark[i]; i--)
			mark[i] = 1;
	}
	int res = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			res++;
	cout << res << endl;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			cout << a[i] << " ";
	cout << endl;
}