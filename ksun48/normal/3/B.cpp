#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, V;
	cin >> N >> V;
	vector<int> t(N), p(N);
	for(int i = 0; i < N; i++){
		cin >> t[i] >> p[i];
	}
	vector<int> ones, twos;
	for(int i = 0; i < N; i++){
		(t[i] == 1 ? ones : twos).push_back(i);
	}
	sort(ones.begin(), ones.end(), [&](int x, int y){
		return p[x] > p[y];
	});
	sort(twos.begin(), twos.end(), [&](int x, int y){
		return p[x] > p[y];
	});
	vector<int> one_psum(ones.size() + 1, 0);
	vector<int> two_psum(twos.size() + 1, 0);
	for(int i = 0; i < (int)ones.size(); i++){
		one_psum[i+1] = p[ones[i]] + one_psum[i];
	}
	for(int i = 0; i < (int)twos.size(); i++){
		two_psum[i+1] = p[twos[i]] + two_psum[i];
	}
	int best_x, best_y, best_score = -1;
	for(int x = 0; 2 * x <= V && x <= (int)twos.size(); x++){
		int y = min(V - 2 * x, (int)ones.size());
		int score = two_psum[x] + one_psum[y];
		if(score > best_score){
			best_x = x;
			best_y = y;
			best_score = score;
		}
	}
	vector<int> idx;
	for(int i = 0; i < best_x; i++){
		idx.push_back(twos[i]);
	}
	for(int i = 0; i < best_y; i++){
		idx.push_back(ones[i]);
	}
	sort(idx.begin(), idx.end());
	cout << best_score << '\n';
	for(int x : idx){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}