#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<pair<int,int> > stuff;
	stuff.push({n, 0});
	int cur = 0;
	while(!stuff.empty()){
		pair<int,int> q = stuff.top();
		if(q.first == 0) break;
		q.second *= -1;
		stuff.pop();
		cur++;
		int v = q.second + (q.first - 1) / 2;
		a[v] = cur;
		stuff.push({v-q.second, -(q.second)});
		stuff.push({q.second+q.first-v-1, -(v+1)});
	}
	for(int x : a) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}