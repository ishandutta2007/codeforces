#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	if(n % 2 == 0){
		cout << "First" << '\n';
		for(int j = 0; j < 2; j++){
			for(int i = 1; i <= n; i++){
				cout << i << ' ';
			}			
		}
		cout << '\n';
		cout << flush;
		int res;
		cin >> res;
	} else {
		cout << "Second" << '\n';
		cout << flush;
		vector<int> which(2*n);
		for(int& x : which){
			cin >> x;
			x--;
		}
		vector<vector<int> > pairs(n);
		for(int i = 0; i < 2*n; i++){
			pairs[which[i]].push_back(i);
		}
		vector<int> other(2*n);
		for(int i = 0; i < n; i++){
			other[pairs[i][0]] = pairs[i][1];
			other[pairs[i][1]] = pairs[i][0];
		}
		vector<int> color(2*n, 0);
		for(int s = 0; s < 2*n; s++){
			int cur = s;
			while(!color[cur]){
				color[cur] = 1;
				cur = (cur + n) % (2*n);
				color[cur] = -1;
				cur = other[cur];
			}
		}
		int csum = 0;
		for(int i = 0; i < 2*n; i++){
			if(color[i] == 1){
				csum += (i+1);
				csum %= (2*n);
			}
		}
		int wh = 1;
		if(csum % (2*n) != 0) wh = -1;
		for(int i = 0; i < 2*n; i++){
			if(color[i] == wh){
				cout << (i+1) << ' ';
			}
		}
		cout << '\n';
	}
}