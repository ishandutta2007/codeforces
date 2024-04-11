#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[1<<9];
vector<P> vec[1<<9];
vector<pair<P, llint> > pvec;

void zeta_transform(llint a[], int n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(j&(1<<i)) a[j] += a[j^(1<<i)];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint f, x;
	for(int i = 0; i < n; i++){
		cin >> f;
		int bit = 0;
		for(int j = 0; j < f; j++){
			cin >> x;
			x--;
			bit |= 1<<x;
		}
		a[bit]++;
	}
	llint c;
	for(int i = 1; i <= m; i++){
		cin >> c;
		cin >> f;
		int bit = 0;
		for(int j = 0; j < f; j++){
			cin >> x;
			x--;
			bit |= 1<<x;
		}
		vec[bit].push_back(make_pair(c, i));
	}
	int S = 1<<9;
	for(int i = 0; i < S; i++) sort(vec[i].begin(), vec[i].end());
	
	for(int i = 0; i < S; i++){
		for(int j = 0; j < min((int)vec[i].size(), 2); j++) pvec.push_back(make_pair(P(i, vec[i][j].first), vec[i][j].second));
	}
	
	zeta_transform(a, 9);
	
	P ans = make_pair(0, -inf); llint ans_i, ans_j;
	for(int i = 0; i < pvec.size(); i++){
		for(int j = 0; j < pvec.size(); j++){
			if(i >= j) continue;
			int mask = pvec[i].first.first | pvec[j].first.first;
			llint cost =  pvec[i].first.second + pvec[j].first.second;
			P p = make_pair(a[mask], -cost);
			if(ans < p){
				ans_i = pvec[i].second;
				ans_j = pvec[j].second;
				ans = p;
			}
		}
	}
	cout << ans_i << " " << ans_j << endl;
	
	return 0;
}