#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> hp(m);
	int tot = 0;
	for(int i = 0; i < m; i++){
		cin >> hp[i]; tot += hp[i];
	}
	int T = ((tot + n - 1) / n);
	hp[0] += n*T - tot;
	priority_queue<pair<int,int> > enemies;
	for(int i = 0; i < m; i++){
		enemies.push({hp[i], i});
	}
	vector<int> group_sizes(m);
	vector<vector<int> > answers(T, vector<int>(m, 0));
	for(int who = 0; who < m; who++){
		int s = 0;
		int e = n*T+1;
		while(s + 1 < e){
			int mid = (s + e) / 2;
			vector<pair<int,int> > used_up;
			int taken = 0;
			while(taken < T && !enemies.empty() && enemies.top().first >= mid){
				pair<int,int> z = enemies.top();
				enemies.pop();
				used_up.push_back(z);
				taken += z.first / mid;
			}
			for(pair<int, int> x : used_up){
				enemies.push(x);
			}
			if(taken >= T){
				s = mid;
			} else {
				e = mid;
			}
		}
		int mid = s;
		if(mid == 0) continue;
		int taken = 0;
		int dex = 0;
		group_sizes[who] = mid;
		while(taken < T){
			pair<int,int> z = enemies.top();
			enemies.pop();
			int f = min(T - taken, z.first / mid);
			if(f == 0){
				cerr << "EPIC FAIL" << '\n';
				exit(0);
			}
			for(int i = 0; i < f; i++){
				answers[dex][who] = z.second;
				dex += 1;
			}
			z.first -= mid * f;
			taken += f;
			enemies.push(z);
		}
	}
	cout << T << '\n';
	for(int i = 0; i < m; i++){
		cout << group_sizes[i] << " \n"[i == m-1];
	}
	for(int t = 0; t < T; t++){
		for(int i = 0; i < m; i++){
			cout << answers[t][i] + 1 << " \n"[i == m-1];
		}
	}
}