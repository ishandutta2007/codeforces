#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	vector<vector<int> > z;
	while(true){
		vector<int> f;
		vector<int> g;
		int a = 0;
		int b = (int)s.size() - 1;
		string s1, s2;
		while(a < b){
			if(s[b] == '('){
				b--; continue;
				s2 += s[b];
			}
			if(s[a] == ')'){
				s1 += s[a];
				a++; continue;
			}
			f.push_back(a);
			g.push_back(b);
			a++; b--;
		}
		if(f.empty()) break;
		reverse(s2.begin(), s2.end());
		s = s1 + s2;
		reverse(g.begin(), g.end());
		for(int v : g) f.push_back(v);
		z.push_back(f);
	}
	cout << z.size() << '\n';
	for(vector<int> r : z){
		cout << r.size() << '\n';
		for(int q : r){
			cout << q+1 << ' ';
		}
		cout << '\n';
	}
}