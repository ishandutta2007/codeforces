#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 210000

int n, m;
vector<pair<int,int> > clause[MAXN];
vector<pair<int,int> > cont[MAXN]; //which clauses is contained in
vector<int> ok[MAXN];

int ans[MAXN];
int sat[MAXN]; // satisfied
int deg[MAXN];

int done[MAXN];

void check(int a);

void assign(int a, int s){ // check ans[a] = s;
	if(ans[a] != 0) return;
	ans[a] = s;
	for(int i = 0; i < cont[a].size(); i++){
		int b = cont[a][i].first;
		deg[b]--;
		if(cont[a][i].second == s){
			sat[b] = 1;
		}
		check(b);
	}
}

void unknown(int a){
	if(ans[a] != 0) return;
	if(cont[a].size() == 0){
		assign(a, 1);
	} else if(cont[a].size() == 1){
		assign(a, cont[a][0].second);
	} else if(ok[a][0]){
		assign(a, cont[a][1].second);
	} else if(ok[a][1]){
		assign(a, cont[a][0].second);
	} else if(cont[a][1].second == cont[a][0].second){
		assign(a,cont[a][0].second);
	}
}

void check(int a){
	if(done[a]) return;
	if(!sat[a] && (deg[a] > 1)) return;
	// either sat[a], or deg[a] <= 1
	done[a] = 1;
	for(int j = 0; j < clause[a].size(); j++){
		int r = clause[a][j].first; // r is variable
		for(int k = 0; k < cont[r].size(); k++){
			if(cont[r][k].first == a){
				if(!sat[a]) assign(r, cont[r][k].second);
				ok[r][k] = 1;
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			int a;
			scanf("%d", &a);
			pair<int,int> edge = make_pair(abs(a), a/abs(a));
			clause[i].push_back(edge);
			cont[abs(a)].push_back(make_pair(i, a/abs(a)));
			ok[abs(a)].push_back(0);
		}
	}
	for(int i = 1; i <= n; i++){
		deg[i] = clause[i].size();
		sat[i] = 0;
		done[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		ans[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		unknown(i);
	}
	for(int i = 1; i <= n; i++){
		check(i);
	}
	for(int i = 1; i <= m; i++){
		assign(i, 1);
		//cout << ans[i] << endl;
	}
	int works = 1;
	for(int i = 1; i <= n; i++){
		int found = 0;
		for(int j = 0; j < clause[i].size(); j++){
			if(ans[clause[i][j].first] == clause[i][j].second) found = 1;
		}
		if(!found) works = 0;
	}
	if(!works){
		printf("NO\n");
	} else {
		printf("YES\n");
		for(int i = 1; i <= m; i++){
			printf("%d", (ans[i]+1)/2);
		}
		printf("\n");
	}
}