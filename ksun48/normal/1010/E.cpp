#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200000;
int qq[MAXN];

void add(int i, int val){
	for (; i < MAXN; i += (i + 1) & -(i + 1)){
		qq[i] = min(qq[i], val);
	}
}

int sum(int i){
	int res = 100000000;
	for (; i >= 0; i -= (i + 1) & -(i + 1)){
		res = min(res, qq[i]);
	}
	return res;
}

vector<int> upd[110000];
vector<int> ask[110000];

int main(){
	cin.sync_with_stdio(0);
	int a, n, m, k;
	cin >> a >> a >> a;
	cin >> n >> m >> k;
	vector<int> minv(3, 10000000);
	vector<int> maxv(3, 0);
	vector<vector<int> > closed(m, vector<int>(3));
	vector<vector<int> > queries(k, vector<int>(3));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			int r;
			cin >> r;
			minv[j] = min(minv[j], r);
			maxv[j] = max(maxv[j], r);
		}
	}
	int bad = 0;
	for(int i = 0; i < m; i++){
		int n0 = 0;
		for(int j = 0; j < 3; j++){
			cin >> closed[i][j];
			if(closed[i][j] > maxv[j]){
				closed[i][j] -= maxv[j];
			} else if(closed[i][j] < minv[j]){
				closed[i][j] -= minv[j];
			} else {
				closed[i][j] = 0;
			}
			if(closed[i][j] == 0) n0++;
		}
		if(n0 == 3){
			bad = 1;
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < 3; j++){
			cin >> queries[i][j];
			if(queries[i][j] > maxv[j]){
				queries[i][j] -= maxv[j];
			} else if(queries[i][j] < minv[j]){
				queries[i][j] -= minv[j];
			} else {
				queries[i][j] = 0;
			}
		}
	}
	if(bad){
		cout << "INCORRECT" << '\n';
		return 0;
	}
	cout << "CORRECT" << '\n';

	vector<int> answers(k, -1); // ??
	for(int v1 = -1; v1 <= 1; v1 += 2){
		for(int v2 = -1; v2 <= 1; v2 += 2){
			for(int v3 = -1; v3 <= 1; v3 += 2){
				// do stuff here;
				for(int i = 0; i < 110000; i++){
					upd[i].clear();
					ask[i].clear();
				}
				for(int i = 0; i < MAXN; i++){
					qq[i] = 100000000;
				}
				for(int i = 0; i < m; i++){
					if(closed[i][0] < 0 || closed[i][1] < 0 || closed[i][2] < 0) continue;
					upd[closed[i][0]].push_back(i);
				}
				for(int i = 0; i < k; i++){
					if(queries[i][0] < 0 || queries[i][1] < 0 || queries[i][2] < 0) continue;
					ask[queries[i][0]].push_back(i);
				}
				for(int x = 0; x < 110000; x++){
					// update all
					for(int i : upd[x]){
						add(closed[i][1], closed[i][2]);
					}
					// answer all queries
					for(int i : ask[x]){
						if(sum(queries[i][1]) <= queries[i][2]){
							answers[i] = 1; // bad
						}
					}
				}

				for(int i = 0; i < m; i++) closed[i][2] *= -1;
				for(int i = 0; i < k; i++) queries[i][2] *= -1;
			}
			for(int i = 0; i < m; i++) closed[i][1] *= -1;
			for(int i = 0; i < k; i++) queries[i][1] *= -1;
		}
		for(int i = 0; i < m; i++) closed[i][0] *= -1;
		for(int i = 0; i < k; i++) queries[i][0] *= -1;
	}
	for(int i = 0; i < k; i++){
		int n0 = 0;
		for(int j = 0; j < 3; j++){
			if(queries[i][j] == 0) n0++;
		}
		if(n0 == 3){
			cout << "OPEN" << '\n';
			continue;
		}
		if(answers[i] == 1){
			cout << "CLOSED" << '\n';
		} else {
			cout << "UNKNOWN" << '\n';			
		}
		// else either closed or unknown
	}
}