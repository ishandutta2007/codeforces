#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, x, y;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x >> y;
		
		llint min_ans;
		if(n >= x+y) min_ans = 1;
		else{
			min_ans = x+y-n+1;
			min_ans = min(min_ans, n);
			//if(max(x, y) == n) min_ans++;
		}
		llint max_ans = min(n, x+y-1);
		cout << min_ans << " " << max_ans << endl;
	}
		
	return 0;
}