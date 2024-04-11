#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	map<string, string> ex;
	map<string, int> num;
	for(int i = 0; i < n; i++){
		string v;
		cin >> v;
		set<string> g;
		for(int a = 0; a < v.size(); a++){
			for(int b = a; b < v.size(); b++){
				g.insert(v.substr(a, b-a+1));
			}
		}
		for(string r : g){
			ex[r] = v;
			num[r]++;
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		string v;
		cin >> v;
		cout << num[v] << " ";
		if(ex.find(v) == ex.end()){
			cout << "-" << '\n';
		} else {
			cout << ex[v] << '\n';
		}
	}
}