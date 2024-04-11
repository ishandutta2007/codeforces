#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, chk[100100], a[100100], b[100100];
vector<int> v[100100];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b), v[b].push_back(a);
	}

	for(int i=1;i<=n;i++) if(v[i].size() != n-1){
		chk[i] = 1;
		for(int x : v[i]) chk[x] = 1;
		int j = 1, c = 0;
		while(chk[j]) j++;

		for(int k=1;k<=n;k++) if(k != i && k != j) a[k] = b[k] = ++c;
		a[i] = b[i] = b[j] = ++c;
		a[j] = ++c;

		cout << "YES\n";
		for(int i=1;i<=n;i++) cout << a[i] << " ";
		cout << "\n";
		for(int i=1;i<=n;i++) cout << b[i] << " ";
		cout << "\n";
		return 0;
	}

	cout << "NO";
}