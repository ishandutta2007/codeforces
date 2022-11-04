#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int n,m,code,N,tot;
int mark[MAXN],match[MAXN];
vector <int> qq[MAXN];
vector <int> adj[MAXN];
map <int,int> mp;
vector < pair<int,int> > q[MAXN];

vector < pair<int,int> > factorize (int x){
	vector < pair<int,int> > ret;
	for (int i=2; i*i<=x; i++){
		int cnt = 0;
		while (x % i == 0){
			x/=i; cnt++;
		}
		if (cnt != 0){
			if (mp.find(i) == mp.end()){
				mp[i] = tot; tot++;
			}
			ret.push_back(pair<int,int>(mp[i],cnt));
		}
	}
	if (x != 1){
		if (mp.find(x) == mp.end()){
			mp[x] = tot;
			tot++;
		}
		ret.push_back(pair<int,int>(mp[x],1));
	}
	return ret;
}

bool dfs (int v){
	if (v == -1)
		return true;
	if (mark[v] == code)
		return false;
	mark[v] = code;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (dfs(match[temp])){
			match[temp] = v;
			match[v] = temp;
			return true;
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++){
		int x; cin >> x;
		q[i] = factorize(x);
		for (int j=0; j<(int)q[i].size(); j++){
			qq[i].push_back(N);
			N+= q[i][j].second;
		}
	}
	for (int i=0; i<m; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		for (int j=0; j<(int)q[e1].size(); j++)
			for (int k=0; k<(int)q[e2].size(); k++) if (q[e1][j].first == q[e2][k].first){
				for (int l=0; l<q[e1][j].second; l++)
					for (int t=0; t<q[e2][k].second; t++){
						adj[qq[e1][j]+l].push_back(qq[e2][k]+t);
						adj[qq[e2][k]+t].push_back(qq[e1][j]+l);
					}
			}
	}
	memset(match, -1, sizeof match);
	int ans = 0;
	for (int i=0; i<N; i++) if (match[i] == -1)
		for (int j=0; j<(int)adj[i].size(); j++) if (match[adj[i][j]] == -1){
			match[i] = adj[i][j];
			match[adj[i][j]] = i;
			ans++;
			break;
		}
	for (int i=0; i<N; i++) if (match[i] == -1){
		code++;
		if (dfs(i))
			ans++;
	}
	cout << ans << endl;
	return 0;
}