#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string type[1000005];
int val[1000005];
bool cri[1000005][2];
vector<int> G[1000005];
bool ans[1000005];

int valdfs(int v)
{
	if(type[v] == "IN") return val[v];
	if(type[v] == "NOT") return val[v] = !valdfs(G[v][0]);
	int u = valdfs(G[v][0]), t = valdfs(G[v][1]);
	if(type[v] == "AND") return val[v] = (u && t);
	if(type[v] == "OR") return val[v] = (u || t);
	if(type[v] == "XOR") return val[v] = (u != t);
}

void ansdfs(int v)
{
	if(type[v] == "IN"){
		ans[v] = true;
		return;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(cri[v][i]) ansdfs(G[v][i]);
	}
}

int main(void)
{
	cin >> n;
	int x, y;
	for(int i = 1; i <= n; i++){
		cin >> type[i];
		if(type[i] == "IN"){
			cin >> x;
			val[i] = x;
		}
		else if(type[i] == "NOT"){
			cin >> x;
			G[i].push_back(x);
		}
		else{
			cin >> x >> y;
			G[i].push_back(x);
			G[i].push_back(y);
		}
	}
	
	valdfs(1);
	
	for(int i = 1; i <= n; i++){
		if(type[i] == "IN") continue;
		if(type[i] == "NOT"){
			cri[i][0] = true;
		}
		if(type[i] == "XOR"){
			cri[i][0] = cri[i][1] = true;
		}
		int x = G[i][0], y = G[i][1];
		if(type[i] == "AND"){
			if(val[x] && val[y]) cri[i][0] = cri[i][1] = true;
			if(!val[x] && val[y]) cri[i][0] = true;
			if(val[x] && !val[y]) cri[i][1] = true;
		}
		if(type[i] == "OR"){
			if(!val[x] && !val[y]) cri[i][0] = cri[i][1] = true;
			if(!val[x] && val[y]) cri[i][1] = true;
			if(val[x] && !val[y]) cri[i][0] = true;
		}
	}
	
	ansdfs(1);
	
	for(int i = 1; i <= n; i++){
		if(type[i] == "IN"){
			bool a = val[1];
			if(ans[i]) a = !a;
			cout << a;
		}
	}
	cout << endl;
	
	return 0;
}