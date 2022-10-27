#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long ans[N];
vector<pair<int, int> > add_element[N], remove_element[N];
multiset<int> global_ms[N];

int main(){
	int n,w;
	scanf("%d %d", &n, &w);
	for(int i = 0; i < n; ++i){
		int cnt;
		scanf("%d", &cnt);
		for(int j = 0; j < cnt; ++j){
			int x,l,r;
			scanf("%d", &x);
			add_element[j].push_back(make_pair(x, i));
			remove_element[j + w - cnt].push_back(make_pair(x, i));
		}
		if(cnt < w){
			add_element[cnt].push_back(make_pair(0, i));
			remove_element[w - 1].push_back(make_pair(0, i));
			add_element[0].push_back(make_pair(0, i));
			remove_element[w - 1 - cnt].push_back(make_pair(0, i));
		}
	}
	for(int i = 0; i < w; ++i){

		for(auto j:add_element[i]){
			int idx = j.second;
			int val = j.first;
			ans[i] -= (global_ms[idx].empty()? 0: *global_ms[idx].rbegin());
			global_ms[idx].insert(val);
			ans[i] += *global_ms[idx].rbegin();
		}	

		if(i < w - 1){
			ans[i + 1] = ans[i];
			for(auto j:remove_element[i]){
				int idx = j.second;
				int val = j.first;
				ans[i + 1] -= (*global_ms[idx].rbegin());
				global_ms[idx].erase(global_ms[idx].find(val));
				ans[i + 1] += (global_ms[idx].empty()? 0: *global_ms[idx].rbegin());
			}
		}
		printf("%lld ",ans[i]);
	}
	printf("\n");
}