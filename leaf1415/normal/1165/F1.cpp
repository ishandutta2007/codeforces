#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int k[200005], rem[200005];
vector<int> vec[200005];

bool check(int x)
{
	vector<pair<int, int> > event;
	for(int i = 1; i <= n; i++){
		int d = *(upper_bound(vec[i].begin(), vec[i].end(), x) - 1);
		event.push_back(make_pair(d, i));
	}
	sort(event.begin(), event.end());
	
	int used = 0;
	for(int i = 1; i <= n; i++) rem[i] = k[i];
	for(int i = 0; i < event.size(); i++){
		int d = event[i].first, t = event[i].second;
		int z = min(d - used, rem[t]);
		used += z;
		rem[t] -= z;
	}
	for(int i = 1; i <= n; i++) used += rem[i]*2;
	return used <= x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> k[i];
	int d, t;
	for(int i = 0; i < m; i++){
		cin >> d >> t;
		vec[t].push_back(d);
	}
	for(int i = 1; i <= n; i++){
		vec[i].push_back(0);
		sort(vec[i].begin(), vec[i].end());
	}
	
	int ub = 1000005, lb = 0, mid;
	while(ub-lb>1){
		mid=(ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	return 0;
}