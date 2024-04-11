#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint m, n;
llint a[200005], b[200005];
llint w[400005], cnt[400005], zero = 200002;
vector<P> vec;
vector<pair<P, llint> > vec2;
llint ans2[200005];
stack<llint> stk;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i]--;
	for(int i = 1; i <= n; i++) cin >> b[i], b[i]--;
	
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(a[i], 0));
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(b[i], 1));
	sort(vec.begin(), vec.end());
	
	llint h = 0, sum = 0;
	for(int i = 0; i < vec.size(); i++){
		llint val = vec[i].first - vec[0].first;
		if(vec[i].second == 0){
			w[zero+h] += val;
			h++;
			if(h > 0) sum -= val;
			else sum += val;
		}
		else{
			h--;
			if(h < 0) sum -= val;
			else sum += val;
			w[zero+h] -= val;
		}
		///cout << vec[i].first << " " << vec[i].second << " " << sum << " " << h << endl;
	}
	//for(int i = -n; i <= n; i++) cout << w[zero+i] << " "; cout << endl;
	
	llint ans = sum, ans_i = 0; h = 0;
	for(int i = 1; i < vec.size(); i++){
		if(vec[i-1].second == 0){
			sum += 2*w[zero+h];
			sum += m;
			w[zero+h] += m;
			h++;
		}
		else{
			h--;
			sum -= 2*w[zero+h];
			sum += m;
			w[zero+h] -= m;
		}
		if(ans > sum){
			ans = sum;
			ans_i = i;
		}
		//for(int i = -n; i <= n; i++) cout << w[zero+i] << " "; cout << endl;
		//cout << sum << endl;
	}
	cout << ans << endl;
	
	for(llint i = 1; i <= n; i++) vec2.push_back(make_pair(make_pair(a[i], 0LL), i));
	for(llint i = 1; i <= n; i++) vec2.push_back(make_pair(make_pair(b[i], 1LL), i));
	sort(vec2.begin(), vec2.end());
	
	for(int i = 0; i < 2*n; i++) vec2.push_back(vec2[i]);
	h = 0;
	for(int i = 0; i < 2*n; i++){
		int p = ans_i + i;
		if(vec2[p].first.second == 0){
			if(h < 0){
				ans2[vec2[p].second] = stk.top();
				stk.pop();
			}
			else stk.push(vec2[p].second);
			h++;
		}
		else{
			if(h > 0){
				ans2[stk.top()] = vec2[p].second;
				stk.pop();
			}
			else stk.push(vec2[p].second);
			h--;
		}
	}
	for(int i = 1; i <= n; i++) cout << ans2[i] << " "; cout << endl;
	
	return 0;
}