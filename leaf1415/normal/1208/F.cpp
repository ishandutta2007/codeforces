#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int n;
int a[1000005];
vector<int> vec[1<<21];
P p[1<<21];

void zeta_transform(P a[], int n)
{
	int S = 1<<n, k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(!(j&(1<<i))){
				k = j^(1<<i);
				if(a[j].first <= a[k].first){
					if(a[j].first <= a[k].second) a[j] = a[k];
					else a[j] = make_pair(a[k].first, a[j].first);
				}
				else{
					if(a[j].second <= a[k].second) a[j] = make_pair(a[j].first, a[k].first);
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--) vec[a[i]].push_back(i);
	
	int S = 1 << 21;
	for(int i = 0; i < S; i++){
		if(vec[i].size() == 0) p[i] = make_pair(0, 0);
		if(vec[i].size() == 1) p[i] = make_pair(vec[i][0], 0);
		if(vec[i].size() >= 2) p[i] = make_pair(vec[i][0], vec[i][1]);
	}
	zeta_transform(p, 21);
	
	int ans = 0;
	for(int i = 1; i <= n-2; i++){
		int mask = 0;
		for(int j = 20; j >= 0; j--){
			if(a[i] & (1<<j)) continue;
			if(p[mask|(1<<j)].second > i) mask |= 1<<j;
		}
		ans = max(ans, a[i]|mask);
	}
	cout << ans << endl;
	
	return 0;
}