#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint m[500005];
llint s[500005];
llint out[500005];

void calc()
{
	llint sum = 0;
	stack<P> stk;
	stk.push(P(-inf, 0));
	
	for(int i = 1; i <= n; i++){
		llint len = 1;
		while(stk.top().first > m[i]){
			sum -= stk.top().first * stk.top().second;
			len += stk.top().second;
			stk.pop();
		}
		stk.push(P(m[i], len));
		sum += m[i] * len;
		s[i] += sum;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> m[i];
	
	calc();
	reverse(m+1, m+n+1);
	reverse(s+1, s+n+1);
	
	calc();
	reverse(m+1, m+n+1);
	reverse(s+1, s+n+1);
	
	for(int i = 1; i <= n; i++) s[i] -= m[i];
	
	llint ans = -1, ans_i;
	for(int i = 1; i <= n; i++){
		if(ans < s[i]){
			ans = s[i];
			ans_i = i;
		}
	}
	
	//for(int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
	//cout << ans_i << endl;
	
	llint mx = inf;
	for(int i = ans_i; i >= 1; i--){
		mx = min(mx, m[i]);
		out[i] = mx;
	}
	mx = inf;
	for(int i = ans_i; i <= n; i++){
		mx = min(mx, m[i]);
		out[i] = mx;
	}
	for(int i = 1; i <= n; i++) cout << out[i] << " "; cout << endl;
	
	return 0;
}