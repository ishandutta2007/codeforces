#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200100;

int sg(int v) { return v < 0 ? -1 : 1; }

vector<pii> ady[maxn];
int literal[maxn][2];
int clause[maxn];
int lit_value[maxn];
bool mk[maxn], tmk[maxn];
bool dead[maxn];

int get_sig(int s, int l){
	if (abs(literal[l][0]) == s) return sg(literal[l][0]);
	return sg(literal[l][1]);
}

void dfs(int s){
	mk[s] = true;
	for (auto nxt : ady[s]){
		if (mk[nxt.first] || dead[nxt.second]) continue;
		clause[nxt.first] = 1;
		int sig = get_sig(s, nxt.second);
		lit_value[nxt.second] = sig == 1 ? 0 : 1;
		dfs(nxt.first);
	}
}

void no(){
	cout << "NO" << endl;
	exit(0);
}

int find_cycle(int s, int f){
	// cout << "FIND_CYCLE: " << s << endl;
	tmk[s] = true;
	for (auto nxt : ady[s]){
		if (tmk[nxt.first]){
			if (nxt.second != f)
				return nxt.second;
			else
				continue;
		}
		int val = find_cycle(nxt.first, nxt.second);
		if (val != -1) return val;
	}	
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		lit_value[i] = -1;

	for (int i = 1; i <= n; ++i){
		int t; cin >> t;
		for (int j = 1; j <= t; ++j){
			int v; cin >> v;
			int p = literal[abs(v)][0] == 0 ? 0 : 1;
			literal[abs(v)][p] = sg(v) * i;
		}
	}	

	for (int i = 1; i <= m; ++i){
		if (literal[i][1] == 0 || sg(literal[i][0]) == sg(literal[i][1])){
			if (literal[i][0] == 0){
				lit_value[i] = 1;
			}
			else if (literal[i][1] == 0)
			{
				clause[abs(literal[i][0])] = 1;
				lit_value[i] = sg(literal[i][0]) == 1 ? 1 : 0;
			}
			else{
				clause[abs(literal[i][0])] = 1;
				clause[abs(literal[i][1])] = 1;
				lit_value[i] = sg(literal[i][0]) == 1 ? 1 : 0;
			}
		}
		else{
			ady[abs(literal[i][0])].push_back({abs(literal[i][1]), i});
			ady[abs(literal[i][1])].push_back({abs(literal[i][0]), i});
		}		
	}

	for (int i = 1; i <= n; ++i){
		if (clause[i] == 1 && !mk[i])
			dfs(i);
	}

	// cout << "HERE" << endl;

	for (int i = 1; i <= n; ++i){
		if (!mk[i]){
			int val = find_cycle(i, -1);
			if (val == -1) no();

			int s = abs(literal[val][0]);
			int sig = sg(literal[val][0]);

			clause[s] = 1;
			lit_value[val] = sig == 1 ? 1: 0;
			dead[val] = true;
			// cout << "VAL: " << val << " " << s << endl;
			dfs(s);
		}
	}

	for (int i = 1; i <= n; ++i)
		assert(clause[i] == 1);
	cout << "YES" << endl;
	for (int i = 1; i <= m; ++i){
		if (lit_value[i] == -1){
			lit_value[i] = 1;
		}
		cout << lit_value[i];
	}
	cout << endl;

	return 0;
}