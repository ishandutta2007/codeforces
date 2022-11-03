#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define lb(a) ((a)&(-(a)))
#define tm adjfisdasafi

const int maxn = 1e5 + 20;
const int maxm = 6;

int adj[maxn] , n , t[maxm] , tm[2 << maxm] , d[2 << maxm];

void cal()
{
	for(int mask = 1; mask < (1 << maxm); mask++)
		tm[mask] = tm[mask ^ lb(mask)] + t[__builtin_ctz(mask)];

	for(int mask = 1; mask < (1 << maxm); mask++)
		for(int i = 0; i < n; i++)
			if(adj[i]&mask)
				d[mask]++;
}

void rem(int p)
{
	for(int mask = 1; mask < (1 << maxm); mask++)
		if(adj[p]&mask)
			d[mask]--;
}

bool check(int add)
{
	for(int mask = 1; mask < (1 << maxm); mask++)
		if(tm[mask] > (d[mask] + bit(mask , add)))
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; i++)
		t[s[i] - 'a']++;

	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int pos;
		string tmp;
		cin >> pos >> tmp;
		pos--;

		for(auto ch : tmp)
			adj[pos] += (1 << (ch - 'a'));
	}

	for(int i = 0; i < n; i++)
		if(!adj[i])
			adj[i] = (1 << 8) - 1;

	cal();

	if(!check(7))
		return cout << "Impossible" << endl , 0;

	string res;
	for(int i = 0; i < n; i++)
	{
		rem(i);
		for(int j = 0; j < 6; j++)
			if(bit(adj[i] , j) && check(j))
			{
				for(int mask = 1; mask < (1 << maxm); mask++)
					if(bit(mask , j))
						tm[mask]--;

				res += (char)(j + 'a');
				break;
			}
	}

	cout << res << endl;
}