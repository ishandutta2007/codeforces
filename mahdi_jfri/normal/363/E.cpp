#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

int a[maxn][maxn] , sum[maxn][maxn] , res[maxn][maxn] , L[maxn] , R[maxn];

pair<int , int> mxp[maxn][maxn] , mxs[maxn][maxn];

bool is[maxn][maxn];

pair<ll , ll> handle(pair<ll , ll> ans , pair<int , int> tmp)
{
	if(ans.first < tmp.first)
		ans = tmp;
	else if(ans.first == tmp.first)
		ans.second += tmp.second;

	return ans;
}

int dist(int a , int b , int x , int y)
{
	return (a - x) * (a - x) + (b - y) * (b - y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , r;
	cin >> n >> m >> r;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	if(!r)
	{
		vector<int> tmp;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				tmp.pb(a[i][j]);
		sort(tmp.begin() , tmp.end());
		reverse(tmp.begin() , tmp.end());
	
		if((int)tmp.size() < 2)
			return cout << "0 0" << endl , 0;

		if(tmp[0] == tmp[1])
		{
			int cnt = 0;
			for(auto x : tmp)
				if(x == tmp[0])
					cnt++;

			cout << 2 * tmp[0] << " " << 1LL * cnt * (cnt - 1) / 2 << endl;
		}
		else
		{
			int cnt1 = 0 , cnt2 = 0;
			for(auto x : tmp)
			{
				if(x == tmp[0])
					cnt1++;
				else if(x == tmp[1])
					cnt2++;
			}

			cout << tmp[0] + tmp[1] << " " << 1LL * cnt1 * cnt2 << endl;
		}

		return 0;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sum[i][j + 1] = sum[i][j] + a[i][j];

	fill(L , L + maxn , -1e9);
	fill(R , R + maxn , -1e9);

	for(int i = 0; i <= r; i++)
	{
		if(!i)
			L[i] = -r , R[i] = r + 1;
		else
			L[i] = L[i - 1] , R[i] = R[i - 1];

		while(dist(L[i] , i , 0 , 0) > r * r)
			L[i]++;
		while(dist(R[i] - 1 , i , 0 , 0) > r * r)
			R[i]--;

	}

	for(int i = r; i < n - r; i++)
		for(int j = r; j < m - r; j++)
			for(int k = i - r; k <= i + r; k++)
				res[i][j] += sum[k][R[abs(i - k)] + j] - sum[k][L[abs(i - k)] + j];

	pair<ll , ll> ans = make_pair(1 , 0);

	for(int i = r; i < n - r; i++)
	{
		for(int j = r; j < m - r; j++)
			mxp[i][j + 1] = handle(mxp[i][j] , make_pair(res[i][j] , 1));
		for(int j = m - r - 1; j >= r; j--)
			mxs[i][j - 1] = handle(mxs[i][j] , make_pair(res[i][j] , 1));
	}

	memset(is , 1 , sizeof is);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = i - r; k <= i + r; k++)
				is[i][j] &= (R[abs(k)] <= L[abs(i - k)] + j || R[abs(i - k)] + j <= L[abs(k)]);

	for(int i = r; i < n - r; i++)
		for(int j = r; j < m - r; j++)
		{
			pair<int , int> tmp = make_pair(0 , 0);

			int P = r , S = m - r - 1;

			for(int k = r; k < n - r; k++)
			{
				while(P <= j && is[abs(k - i)][abs(j - P)])
					P++;
				while(P > r && !is[abs(k - i)][abs(j - P + 1)])
					P--;

				while(S > j && is[abs(k - i)][abs(j - S)])
					S--;
				while(S < m - r - 1 && !is[abs(k - i)][abs(j - S - 1)])
					S++;

				tmp = handle(tmp , mxp[k][P]);
				tmp = handle(tmp , mxs[k][S]);
			}

			tmp.first += res[i][j];

			ans = handle(ans , tmp);
		}

	if(ans.second == 0)
		ans.first = 0;

	cout << ans.first << " " << ans.second / 2 << endl;
}