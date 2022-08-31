#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	{
		string g = s + ">";
		vector<int> sz;
		int a = 0;
		for(int i = 0; i < n; i++){
			a++;
			if(g[i] == '>'){
				sz.push_back(a);
				a = 0;
			}
		}
		int cur = n;
		for(int b : sz){
			for(int r = cur - b; r < cur; r++){
				cout << (r + 1) << ' ';
			}
			cur -= b;
		}
		cout << '\n';
	}
	{
		string g = s + "<";
		vector<int> sz;
		int a = 0;
		for(int i = 0; i < n; i++){
			a++;
			if(g[i] == '<'){
				sz.push_back(a);
				a = 0;
			}
		}
		int cur = 0;
		for(int b : sz){
			for(int r = cur + b - 1; r >= cur; r--){
				cout << (r + 1) << ' ';
			}
			cur += b;
		}
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}