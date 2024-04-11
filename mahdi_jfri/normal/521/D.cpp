#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double
#define int ll

const int maxn = 1e5 + 20;

vector<int> Add[maxn];

int a[maxn] , mx[maxn] , pt[maxn];
int type[maxn] , p[maxn] , b[maxn];

bool cmp1(int x , int y)
{
	return b[x] > b[y];
}

bool cmp2(int x , int y)
{
	return type[x] < type[y];
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k , n , m;
	cin >> k >> n >> m;

	for(int i = 0; i < k; i++)
		cin >> a[i];

	vector<pair<ld , int> > Mul;
	for(int i = 0; i < n; i++)
	{
		cin >> type[i] >> p[i] >> b[i];
		p[i]--;

		if(type[i] == 1 && mx[p[i]] < b[i])
			mx[p[i]] = b[i] , pt[p[i]] = i;

		if(type[i] == 2)
			Add[p[i]].pb(i);

		if(type[i] == 3)
			Mul.pb({b[i] , i});
	}

	for(int i = 0; i < k; i++)
	{
		if(mx[i] > a[i])
		{
			b[pt[i]] -= a[i];
			Add[i].pb(pt[i]);
		}

		sort(Add[i].begin() , Add[i].end() , cmp1);

		for(auto x : Add[i])
		{
			ld y = (ld)(a[i] + b[x]) / (ld)(a[i]);
			Mul.pb({y , x});

			a[i] += b[x];
		}
	}

	sort(Mul.begin() , Mul.end());
	reverse(Mul.begin() , Mul.end());

	vector<int> ans;
	if(m)
		for(auto x : Mul)
		{
			ans.pb(x.second);
	
			if((int)ans.size() == m)
				break;
		}

	sort(ans.begin() , ans.end() , cmp2);
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x + 1 << " ";
	cout << endl;

}