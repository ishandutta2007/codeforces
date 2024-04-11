#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, w, l;
llint a[1000005];
llint ans[1000005];
vector<llint> vec[1000005][2];

void calc()
{
	llint len = w-l+1;
	deque<llint> deq;
	for(int i = 1; i <= l; i++){
		while(deq.size() && a[deq.back()] < a[i]) deq.pop_back();
		deq.push_back(i);
		if(i >= w-l+1 || a[deq.front()] >= 0) ans[i] += a[deq.front()];
		if(deq.front() == i-len+1) deq.pop_front();
	}
	deq.clear();
	for(int i = 1; i <= l; i++){
		if(w+1-i <= l) break;
		while(deq.size() && a[deq.back()] < a[l+1-i]) deq.pop_back();
		deq.push_back(l+1-i);
		if(a[deq.front()] >= 0) ans[w+1-i] += a[deq.front()];
		if(deq.front() == (l+1-i)+len-1) deq.pop_front();
	}
	if(2*l >= w) return;
	
	llint mx = 0;
	for(int i = 1; i <= l; i++) mx = max(mx, a[i]);
	vec[l+1][0].push_back(mx);
	vec[w-l][1].push_back(mx);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w;
	for(int i = 1; i <= n; i++) ans[i] = 0;
	
	for(int i = 1; i <= n; i++){
		cin >> l;
		for(int j = 1; j <= l; j++) cin >> a[j];
		calc();
		//for(int j = 1; j <= w; j++) cout << ans[j] << " "; cout << endl;
	}
	
	llint sum = 0;
	for(int i = 1; i <= w; i++){
		for(int j = 0; j < vec[i][0].size(); j++) sum += vec[i][0][j];
		ans[i] += sum;
		for(int j = 0; j < vec[i][1].size(); j++) sum -= vec[i][1][j];
	}
	
	for(int i = 1; i <= w; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}