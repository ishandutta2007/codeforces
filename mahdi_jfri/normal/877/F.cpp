#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 320;

int t[maxn] , a[maxn] , x[maxn] , pk[maxn] , mk[maxn] , id[maxn];
int cnt[maxn] , l[maxn] , r[maxn];

ll sum[maxn] , res , ans[maxn];

bool cmp(int a , int b)
{
	if(l[a] / sq != l[b] / sq)
		return l[a] / sq < l[b] / sq;

	return r[a] < r[b];
}

int get(vector<ll> &tmp , ll x)
{
	int ans = lower_bound(tmp.begin() , tmp.end() , x) - tmp.begin();
	
	if(ans < (int)tmp.size() && tmp[ans] != x)
		ans = tmp.size();

	return ans;
}

void right(int p , int val)
{
	if(val == -1)
		cnt[id[p]]--;

	res += cnt[mk[p]] * val;

	if(val == 1)
		cnt[id[p]]++;
}

void left(int p , int val)
{
	if(val == -1)
		cnt[id[p]]--;

	res += cnt[pk[p]] * val;

	if(val == 1)
		cnt[id[p]]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> t[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(t[i] == 2)
			a[i] *= -1;
	}

	vector<ll> tmp;

	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i] , tmp.pb(sum[i]);
	tmp.pb(0);

	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());

	for(int i = 0; i <= n; i++)
	{
		pk[i] = get(tmp , sum[i] + k);
		mk[i] = get(tmp , sum[i] - k);
		id[i] = get(tmp , sum[i]);
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i];
		r[i]++;

		x[i] = i;
	}

	sort(x , x + q , cmp);

	int L = 1 , R = 1;

	for(int i = 0; i < q; i++)
	{
		int shit = x[i];

		while(R < r[shit])
			right(R , 1) , R++;
		while(l[shit] < L)
			L-- , left(L , 1);
		while(R > r[shit])
			R-- , right(R , -1);
		while(l[shit] > L)
			left(L , -1) , L++;

		ans[shit] = res + cnt[pk[L - 1]];
	}

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;

}