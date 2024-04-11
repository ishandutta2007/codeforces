#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
int allcnt = 0;
vector <int> dsu, rang;
int pred(int a){
	if(dsu[a] == a) return a;
	else return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		allcnt--;
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    dsu.resize(n);
    rang.resize(n);
    vector <int> c(n);
    for(int i = 0; i < n; i++)
    {
    	dsu[i] = i;
    	rang[i] = 1;
    	cin >> c[i];
    }
    vector <pair <int, pair <int, int> > > vec;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	vec.push_back({c[a] ^ c[b], {a, b}});
    }
    sort(vec.begin(), vec.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < vec.size(); i++)
    {
    	int j = i;
    	allcnt = n;
    	cnt++;
    	while(j < vec.size() && vec[j].first == vec[i].first)
    	{
    		unite(vec[j].second.first, vec[j].second.second);
    		j++;
    	}
    	ans += power(2, allcnt);
    	if(ans >= const1)
    	{
    		ans -= const1;
    	}
    	while(i < j)
    	{
    		dsu[vec[i].second.first]= vec[i].second.first;
    		dsu[vec[i].second.second] = vec[i].second.second;
    		rang[vec[i].second.first] = 1;
    		rang[vec[i].second.second] = 1;
    		i++;
    	}
    	i--;
    }
    ans += power(2, n) * ((power(2, k) - cnt + const1) % const1) % const1;
    if(ans >= const1)
    {
    	ans -= const1;
    }
    cout << ans;
    return 0;
}