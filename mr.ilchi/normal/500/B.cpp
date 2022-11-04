#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300+10;

bool mark[MAXN];
int n;
int p[MAXN];
string adj[MAXN];
vector<int> pos,val;

void dfs (int v){
	mark[v] = true;
	for (int i=0; i<n; i++) if (!mark[i] && adj[v][i]=='1')
		dfs(i);
	pos.push_back(v);
	val.push_back(p[v]);
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> adj[i];
	for (int i=0; i<n; i++) if (!mark[i]){
		val.clear();
		pos.clear();
		dfs(i);
		sort(pos.begin(),pos.end());
		sort(val.begin(),val.end());
		for (int j=0; j<(int)pos.size(); j++)
			p[pos[j]] = val[j];
	}
	for (int i=0; i<n; i++)
		cout << p[i] << ' ';
	cout << endl;
	return 0;
}