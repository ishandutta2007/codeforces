#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
P p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
		sort(p+1, p+n+1);
		
		priority_queue<llint, vector<llint>, greater<llint> > Q;
		
		llint ans = 0, cnt = 0;
		for(int i = n; i >= 1; i--){
			Q.push(p[i].second);
			if(cnt < p[i].first - (i-1)){
				cnt++;
				ans += Q.top();
				Q.pop();
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}