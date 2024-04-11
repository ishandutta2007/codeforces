#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int maxn = 100100;

vi ady[maxn];
bool dead[maxn];
bool mk[maxn];
bool bone[maxn];

void kill(int s){
	dead[s] = true;
	for (int i = 0; i < (int)ady[s].size(); ++i){
		int nxt = ady[s][i];
		if (dead[nxt]) continue;
		if (ady[nxt].size() == 2) 
			kill(nxt);
	}
}

void yes(){
	cout << "Yes" << endl;
	exit(0);
}

void no(){
	cout << "No" << endl;
	exit(0);
}

int dfs(int s){
	mk[s] = true;
	int ans = 0;
	for (int i = 0; i < (int)ady[s].size(); ++i){
		int nxt = ady[s][i];
		if (mk[nxt] || dead[nxt]) continue;
		int cur = dfs(nxt);
		if (cur > 1) no();
		ans += cur;
	}
	if (!ans && bone[s]) ans++;
	return ans;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}	

	for (int i = 1; i <= n; ++i){
		if (ady[i].size() == 1) 
			kill(i);
		if (ady[i].size() > 3);
			bone[i] = true;
	}

	for (int i = 1; i <= n; ++i){
		if (ady[i].size() == 3){
			int td = 0;
			for (int j = 0; j < 3; ++j)
				if (dead[ady[i][j]]) ++td;
			
			if (td == 2){
				dead[i] = true;
				for (int j = 0; j < 3; ++j)
					if (!dead[ady[i][j]]) bone[ady[i][j]] = true;
			}
			else{
				bone[i] = true;
			}
		}
	}

	// for (int i = 1; i <= n; ++i){
	// 	cout << i << " " << bone[i] << " " << dead[i] << endl;
	// }

	int fb = 0;

	for (int i = 1; i <= n && fb == 0; ++i)
		if (!dead[i] && bone[i]) fb = i;

	if (fb == 0) yes();

	int val = dfs(fb);

	if (val <= 2) yes();
	else no();
}