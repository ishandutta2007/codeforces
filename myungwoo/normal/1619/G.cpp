#include <bits/stdc++.h>
using namespace std;

struct Solver {
	struct Point {
		int x, y, idx;
	};
	int N, K;
	vector<int> timer;
	vector<Point> arr;
	vector<int> par;

	int find(int n){ return par[n] == n ? n : (par[n] = find(par[n])); }
	void combine(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		par[b] = a;
		timer[a] = min(timer[a], timer[b]);
	}

	int solve(){
		cin >> N >> K;
		timer.resize(N+1); arr.resize(N+1); par.resize(N+1);
		for (int i=1;i<=N;i++){
			par[i] = i;
			cin >> arr[i].x >> arr[i].y >> timer[i];
			arr[i].idx = i;
		}
		sort(arr.begin()+1, arr.end(), [](const Point& a, const Point& b){
			return a.x != b.x ? a.x < b.x : a.y < b.y;
		});
		for (int i=1;i<N;i++) if (arr[i].x == arr[i+1].x){
			if (arr[i+1].y <= arr[i].y+K){
				combine(arr[i].idx, arr[i+1].idx);
			}
		}
		sort(arr.begin()+1, arr.end(), [](const Point& a, const Point& b){
			return a.y != b.y ? a.y < b.y : a.x < b.x;
		});
		for (int i=1;i<N;i++) if (arr[i].y == arr[i+1].y){
			if (arr[i+1].x <= arr[i].x+K){
				combine(arr[i].idx, arr[i+1].idx);
			}
		}
		vector<int> times;
		for (int i=1;i<=N;i++) if (par[i] == i){
			times.push_back(timer[i]);
		}
		sort(times.begin(), times.end());
		for (int ans=0;;ans++){
			if (times.size() <= ans+1 || times[times.size()-ans-2] <= ans) return ans;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;){
		Solver s; cout << s.solve() << '\n';
	}
}