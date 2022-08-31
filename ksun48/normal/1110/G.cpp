#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > edges;
string s;

void solve(){
	int n;
	cin >> n;
	edges.assign(n, {});
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b); edges[b].push_back(a);
	}
	cin >> s;
	int nw = 0;
	for(char x : s){
		if(x == 'W') nw++;
	}
	if(n <= 2){
		cout << "Draw" << '\n'; return;
	}
	if(n == 3){
		if(nw >= 2){
			cout << "White" << '\n'; return;
		}
		cout << "Draw" << '\n'; return;
	}
	for(int i = 0; i < n; i++){
		if(edges[i].size() >= 4){
			cout << "White" << '\n'; return;
		}
	}
	for(int i = 0; i < n; i++){
		int wn = 0;
		if(s[i] == 'W') wn++;
		for(int x : edges[i]){
			if(s[x] == 'W') wn++;
		}
		if(wn >= 2){
			cout << "White" << '\n'; return;
		}
	}
	for(int i = 0; i < n; i++){
		int nonleaf = 0;
		for(int x : edges[i]){
			if(int(edges[x].size()) != 1){
				nonleaf++;
			}
		}
		if(nonleaf >= 2 && int(edges[i].size()) >= 3){
			cout << "White" << '\n'; return;
		}
		if(s[i] == 'W'){
			if(nonleaf >= 1 && int(edges[i].size()) >= 2){
				cout << "White" << '\n'; return;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] == 'W'){
			if(int(edges[i].size()) >= 3){
				cout << "White" << '\n'; return;
			}
			for(int x : edges[i]){
				if(int(edges[x].size()) >= 3){
					cout << "White" << '\n'; return;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(int(edges[i].size()) == n-1){
			cout << "Draw" << '\n'; return;
		}
	}
	vector<int> r;
	for(int i = 0; i < n; i++){
		if(int(edges[i].size()) == 3){
			r.push_back(i);
		}
	}
	if(r.size() == 0){
		if(nw == 0){
			cout << "Draw" << '\n'; return;
		} else if(nw == 1){
			cout << "Draw" << '\n'; return;			
		} else {
			if(n % 2 == 1){
				cout << "White" << '\n'; return;				
			} else {
				cout << "Draw" << '\n'; return;
			}
		}
	}
	if(nw == 0){
		if(r.size() < 2){
			cout << "Draw" << '\n'; return;
		}
		if(n % 2 == 1){
			cout << "White" << '\n'; return;
		} else {
			cout << "Draw" << '\n'; return;
		}
	}
	if(nw == 1){
		if(n % 2 == 0){
			cout << "White" << '\n'; return;
		} else {
			cout << "Draw" << '\n'; return;
		}		
	}
	for(int i = 0; i < n; i++){
		for(int x : edges[i]){
			if(i < x) cout << i << " " << x << endl;
		}
	}
	cout << s << endl;
	fflush(stdout);
	assert(false);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}