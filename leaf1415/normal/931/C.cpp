#include <iostream>
#define llint long long
const llint inf = 1e18;

using namespace std;

int n;
llint x[100005];
llint lb, ub, mid;
llint sum, S;
llint cnt[3];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	
	lb = inf, ub = -inf;
	for(int i = 1; i <= n; i++){
		lb = min(lb, x[i]);
		ub = max(ub, x[i]);
	}
	
	if(ub - lb <= 1){
		cout << n << endl;
		for(int i = 1; i <= n; i++){
			cout << x[i];
			if(i != n) cout << " ";
		}
		cout << endl;
		return 0;
	}
	
	mid = lb + 1;
	for(int i = 1; i <= n; i++){
		sum += x[i];
		if(x[i] == lb) cnt[0]++;
		if(x[i] == ub) cnt[2]++;
		if(x[i] == mid) cnt[1]++;
	}
	S = sum - mid*n;
	
	
	bool flag = false;
	llint tmp, ans = n, ans_p;
	
	if(S < 0) S *= -1, flag = true;
	for(llint p = S; 2*p <= n+S; p++){
		llint m = p - S;
		if(flag) tmp = min(ans, min(p, cnt[0]) + min(m, cnt[2]) + min(n-p-m, cnt[1]));
		else tmp = min(ans, min(p, cnt[2]) + min(m, cnt[0]) + min(n-p-m, cnt[1]));
		if(ans > tmp){
			ans = tmp;
			ans_p = p;
		}
	}
	llint ans_m = ans_p - S;
	
	if(flag){
		llint t = ans_m;
		ans_m = ans_p;
		ans_p = t;
	}
	
	cout << ans << endl;
	for(int i = 1; i <= ans_p; i++) cout << ub << " ";
	for(int i = 1; i <= ans_m; i++) cout << lb << " ";
	for(int i = 1; i <= n - ans_p - ans_m; i++) cout << mid << " ";
	cout << endl;
	
	return 0;
}