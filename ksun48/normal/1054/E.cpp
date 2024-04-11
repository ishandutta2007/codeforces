#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct step {
	int a, b, c, d;
	step (int a, int b, int c, int d): a(a), b(b), c(c), d(d){}
};

int n, m;

vector<step> solve(vector<vector<string> > s){
	vector<step> ans;
	vector<int> freq0(m, 0);
	vector<int> freq1(m, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			string g = s[i][j];
			reverse(g.begin(), g.end());
			for(char x : g){
				if(x == '0'){
					if(i == 0){
						ans.push_back(step(i, j, 0, (j+1) % m));
						freq0[(j+1)%m]++;
					} else {
						ans.push_back(step(i, j, 0, j));
						freq0[j]++;
					}
				} else {
					if(i == n-1){
						ans.push_back(step(i, j, n-1, (j+1) % m));
						freq1[(j+1)%m]++;
					} else {
						ans.push_back(step(i, j, n-1, j));
						freq1[j]++;
					}
				}
			}
		}
	}
	for(int i = 1; i < m; i++){
		for(int a = 0; a < freq0[i]; a++){
			ans.push_back(step(0, i, 0, 0));	
		}
		for(int a = 0; a < freq1[i]; a++){
			ans.push_back(step(n-1, i, n-1, 0));	
		}
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<vector<string> > s1(n, vector<string>(m));
	vector<vector<string> > s2(n, vector<string>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> s1[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> s2[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) reverse(s2[i][j].begin(), s2[i][j].end());
	int s = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) s += s1[i][j].size();

	vector<step> ans1 = solve(s1);
	vector<step> ans2 = solve(s2);
	reverse(ans2.begin(), ans2.end());
	for(step v : ans2){
		ans1.push_back(step(v.c, v.d, v.a, v.b));
	}
	assert(ans2.size() <= 4 * s);
	cout << ans1.size() << '\n';
	for(step v : ans1){
		cout << v.a+1 << " " << v.b+1 << " " << v.c+1 << " " << v.d+1 << '\n';
	}
}