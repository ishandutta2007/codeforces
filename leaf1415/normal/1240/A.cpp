#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint Q;
llint n;
llint p[200005];
llint x, a, y, b, k;

bool check(llint m)
{
	if(m >= n+1) return true;
	vector<llint> vec;
	for(int i = 1; i <= m; i++){
		llint sum = 0;
		if(i % a == 0) sum += x;
		if(i % b == 0) sum += y;
		vec.push_back(sum);
	}
	sort(vec.rbegin(), vec.rend());
	
	llint sum = 0;
	for(int i = 0; i < vec.size(); i++){
		sum += p[i] / 100 * vec[i];
	}
	return sum >= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> p[i];
		cin >> x >> a >> y >> b >> k;
		
		sort(p, p+n);
		reverse(p, p+n);
		
		llint ub = n+1, lb = 0, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		if(ub > n) ub = -1;
		cout << ub << "\n";
	}
	flush(cout);
	
	return 0;
}