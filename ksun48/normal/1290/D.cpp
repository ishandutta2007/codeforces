#include <bits/stdc++.h>
using namespace std;

bool TEST = false;

int nq = 0;
bool taste(int x){
	nq++;
	if(TEST) return false;
	cout << '?' << ' ' << x + 1 << '\n';
	cout << flush;
	char c;
	cin >> c;
	return c == 'Y';
}

void reset(){
	cout << 'R' << '\n';
	cout << flush;
}

void answer(int x){
	cout << '!' << ' ' << x << '\n';
	cout << flush;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<bool> seen(n, false);
	vector<int> what(n);
	for(int i = 0; i < n; i += k){
		for(int j = i; j < i + k; j++){
			seen[j] = taste(j);
			what[j] = seen[j] ? what[j-1] : j;
		}
		reset();
	}

	int r = n / k;
	vector<vector<int> > needs(r);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < r; j++){
			if(i < j) needs[i].push_back(j);
		}
	}
	for(int f = 0; f < r; f++){
		while(!needs[f].empty()){
			int cur = f;
			vector<int> path = {cur};
			while(true){
				if(needs[cur].empty()) break;
				path.push_back(needs[cur].back());
				needs[cur].pop_back();
				cur = path.back();
			}
			vector<vector<int> > paths(2);
			for(int a : path){
				for(int j = 0; j < k; j++){
					paths[0].push_back(what[a * k + j]);
					paths[1].push_back(what[a * k + k-1-j]);
				}
			}
			for(vector<int> p : paths){
				int last = -1;
				for(int c : p){
					bool cseen = taste(c);
					if(c != last && cseen) seen[c] = true;
					last = c;
				}
				reset();
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!seen[i]) ans += 1;
	}
	answer(ans);
}