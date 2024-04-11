#include <bits/stdc++.h>
using namespace std;

const string imp = "IMPOSSIBLE";
const int MAXN = 1000000+10;

int n,q,cnt,cur;
int start[MAXN],finish[MAXN],L[MAXN],R[MAXN],par[MAXN];
vector<int> Q;
vector<int> lef[MAXN],rig[MAXN];

int dfs (int v, int end){
	start[v] = cnt++;
	int cur = v;
	if (!lef[v].empty()){
		if (cur+1 > lef[v][0])
			return -1;
		L[v] = ++cur;
		par[cur] = v;
		int end = v;
		for (int i=0; i<(int)lef[v].size(); i++)
			end = max(end, lef[v][i]);
		cur = dfs(cur, end);
		Q.push_back(v);
		if (cur == -1)
			return -1;
	}else
		Q.push_back(v);
	if (!rig[v].empty()){
		if (cur+1>rig[v][0])
			return -1;
		for (int i=0; i<(int)rig[v].size(); i++)
			end = max(end, rig[v][i]);
		R[v] = ++cur;
		par[cur] = v;
		cur = dfs(cur, end);
	}else if (cur<end){
		R[v] = ++cur;
		par[cur] = v;
		cur = dfs(cur,end);
	}
	finish[v] = cnt;
	return cur;
}

int main(){
	cin >> n >> q;
	for (int o=0; o<q; o++){
		int a,b; cin >> a >> b;
		string s; cin >> s;
		a--; b--;
		if (b <= a){
			cout << imp << endl;
			return 0;
		}
		if (s == "LEFT")
			lef[a].push_back(b);
		else
			rig[a].push_back(b);
	}
	for (int i=0; i<n; i++){
		sort(lef[i].begin(), lef[i].end());
		sort(rig[i].begin(), rig[i].end());
	}
	memset(L,-1, sizeof L);
	memset(R,-1, sizeof R);
	if (dfs(0,n-1) != n-1){
		cout << imp << endl;
		return 0;
	}
	for (int i=0; i<n; i++){
		bool flag = true;
		for (int j=0; j<(int)lef[i].size(); j++) if (!((L[i]!=-1) && (start[L[i]]<=start[lef[i][j]] && start[lef[i][j]] <= finish[L[i]]))) flag = false;
		for (int j=0; j<(int)rig[i].size(); j++) if (!((R[i]!=-1) && (start[R[i]]<=start[rig[i][j]] && start[rig[i][j]] <= finish[R[i]]))) flag = false;
		if (!flag){
			cout << imp << endl;
			return 0;
		}
	}
	for (int i=0; i<(int)Q.size(); i++)
		cout << Q[i]+1 << ' ';
	cout << endl;
	return 0;
}