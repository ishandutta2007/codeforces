#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, q;
set<string> c;
set<string> d;
string a[36], b[36];
void dfs(string r){
	if(c.find(r) != c.end()) return;
	if(r.size() == n){
		d.insert(r);
		return;
	}
	for(int i = 0; i < 1; i++){
		for(int j = 0; j < q; j++){
			if(b[j][0] == r[i]){
				string s = r.substr(0,i)+a[j]+r.substr(i+1);
				dfs(s);
			}
		}
	}
}


int main(){
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		cin >> a[i] >> b[i];
	}
	string l = "a";
	dfs(l);
	cout << d.size() << endl;
}