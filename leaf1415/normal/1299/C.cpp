#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#define llint long long

using namespace std;
typedef pair<double, llint> P;

int n;
int a[1000005];
stack<P> stk;
vector<P> vec;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	//cin >> n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i++){
		double w = a[i]; llint len = 1;
		while(stk.size() && stk.top().first > w){
			w = w*len + stk.top().first*stk.top().second;
			len += stk.top().second;
			w /= len;
			stk.pop();
		}
		stk.push(P(w, len));
	}
	while(stk.size()) vec.push_back(stk.top()), stk.pop();
	reverse(vec.begin(), vec.end());
	
	for(int i = 0; i < vec.size(); i++){
		llint x = vec[i].second;
		for(int j = 0; j < x; j++) printf("%.11f\n", vec[i].first);
	}
	flush(cout);
	
	return 0;
}