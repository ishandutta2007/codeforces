#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint n, T, a, b;
llint d[200005], t[200005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 1; q <= Q; q++){
		cin >> n >> T >> a >> b;
		for(int i = 1; i <= n; i++) cin >> d[i];
		for(int i = 1; i <= n; i++) cin >> t[i];
		
		vec.clear();
		for(int i = 1; i <= n; i++){
			vec.push_back(P(t[i], d[i]));
		}
		vec.push_back(P(T+1, 0));
		sort(vec.begin(), vec.end());
		
		llint easy = 0, diff = 0;
		for(int i = 1; i <= n; i++) diff += d[i];
		easy = n - diff;
		
		llint ans = 0, rem = vec[0].first-1;
		if(rem <= a*easy) ans += rem / a, rem = 0;
		else rem -= a*easy, ans += easy;
		if(rem <= b*diff) ans += rem / b, rem = 0;
		else rem -= b*diff, ans += diff;
		
		ans = max(ans, 0LL);
		
		llint sum = 0;
		for(int i = 0; i < n; i++){
			if(vec[i].second == 0) sum += a, easy--;
			else sum += b, diff--;
			if(sum > (vec[i+1].first-1)) continue;
			
			//cout << i << " " << sum << endl;
			
			llint rem = (vec[i+1].first-1) - sum, tmp = i+1;
			
			//cout << rem << " " << tmp << " " << easy << endl;
			
			if(rem <= a*easy) tmp += rem / a, rem -= rem / a * a;
			else rem -= a*easy, tmp += easy;
			
			//cout << tmp << endl;
			
			if(rem <= b*diff) tmp += rem / b, rem -= rem / b * b;
			else rem -= b*diff, tmp += diff;
			
			//cout << tmp << endl;
			
			ans = max(ans, tmp);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}