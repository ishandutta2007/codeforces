#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int p[n], a[n], b[n];
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int m;
	cin >> m;
	multiset<int> f[4];
	map<int,int> c1;
	map<int,int> c2;
	for(int i = 0; i < n; i++){
		f[a[i]].insert(p[i]);
		c1[p[i]] = a[i];
		c2[p[i]] = b[i];
		if(a[i] != b[i]){
			f[b[i]].insert(p[i]);
		}
	}
	for(int i = 0; i < m; i++){
		int c;
		cin >> c;
		if(f[c].empty()){
			cout <<-1 << " ";
			continue;
		}
		int d = *f[c].begin();
		cout << d << " ";
		int a1 = c1[d];
		int b1 = c2[d];
		f[a1].erase(f[a1].find(d));
		if(a1 != b1){
			f[b1].erase(f[b1].find(d));
		}
	}
	cout << endl;
}