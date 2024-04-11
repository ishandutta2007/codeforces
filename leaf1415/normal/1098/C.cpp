#include <iostream>
#include <queue>
#include <vector>
#define llint long long

using namespace std;

llint n, s;
llint a[100005];
queue<int> Q[100005];
vector<int> vec[100005];
llint ans[100005];

bool check(llint m)
{
	for(int i = 1; i <= n; i++) a[i] = 1;
	
	llint rem = n*(n+1)/2 - s, p = 2;
	if(m == 1) return rem == 0;
	
	for(int i = n; i >= 1; i--){
		if(rem <= 0) return true;
		if(i <= p) return false;
		if(rem >= i-p){
			rem -= i-p;
			a[i]--;
			a[p]++;
			if(a[p] >= a[p-1]*m) p++;
		}else{
			llint d = i-rem;
			a[i]--;
			a[d]++;
			return true;
		}
	}
}

int main(void)
{
	cin >> n >> s;
	
	if(s > n*(n+1)/2){
		cout << "No" << endl;
		return 0;
	}
	
	llint ub = n, lb = 0, mid;
	while(ub - lb > 1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	
	if(ub >= n){
		cout << "No" << endl;
		return 0;
	}
	
	check(ub);
	
	int id = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			Q[i].push(id);
			vec[i].push_back(id++);
		}
	}
	
	int cnt;
	for(int i = 2; i <= n; i++){
		cnt = 0;
		for(int j = 0; j < a[i]; j++){
			ans[vec[i][j]] = Q[i-1].front();
			cnt++;
			if(cnt >= ub) cnt = 0, Q[i-1].pop();
		}
	}
	
	cout << "Yes" << endl;
	for(int i = 2; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}