#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k, t;
llint a[200005];
llint l[200005], r[200005], d[200005];
vector<P> vec;

bool check(llint x)
{
	if(x == 0) return true;
	
	llint sum = 0, left = 0, right = 0;
	for(int i = 0; i < vec.size(); i++){
		int id = vec[i].second;
		if(d[id] <= a[x]) continue;
		
		if(l[id] <= right){
			right = max(right, r[id]);
		}
		else{
			sum += 2*(right-left);
			left = l[id];
			right = r[id];
		}
	}
	sum += 2*(right-left);
	sum += n+1;
	return sum <= t;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n >> k >> t;
	for(int i = 1; i <= m; i++) cin >> a[i];
	sort(a+1, a+m+1);
	reverse(a+1, a+m+1);
	
	for(int i = 1; i <= k; i++){
		cin >> l[i] >> r[i] >> d[i];
		l[i]--;
		vec.push_back(P(l[i], i));
	}
	sort(vec.begin(), vec.end());
	
	llint ub = m+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}