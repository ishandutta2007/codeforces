#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)6e5 + 10;

vector<pii> ady[MAXN];
int ptr[MAXN];
bool mk[MAXN];
int ID[MAXN];

int tot;
map<string,int> M;
string LST[MAXN];

int d;
int e_tour[MAXN];

int getid(string s){
	if (!M.count(s)){
		LST[tot] = s;
		M[s] = tot++;
	}
	return M[s];
}

void dfs(int s){
	for (;ptr[s] < (int)ady[s].size(); ++ptr[s]){
		pii nx = ady[s][ptr[s]];
		if (mk[nx.second]) continue;
		mk[nx.second] = true;
		dfs(nx.first);
	}
	e_tour[d++] = s;
}

string make(char a, char b){
	string ans = "";
	ans += a;
	ans += b;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	tot = d = 0;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		int u = getid( make(s[0], s[1]) );
		int v = getid( make(s[1], s[2]) );
		ady[u].push_back(MP(v, i));
		ID[v]++;
	}

	int begin = 0, bad = 0;
	for (int i = 0; i < tot; ++i){
		if ((int)ady[i].size() > ID[i])
		{
			bad += ady[i].size() - ID[i];
			if (bad > 1){
				cout << "NO" << endl;
				return 0;
			}
			begin = i;
		}
	}

	dfs(begin);
	if (d != n + 1){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		cout << LST[e_tour[d - 1]];
		for (int i = d - 2; i >= 0; --i)
			cout << LST[e_tour[i]][1];
		cout << endl;
	}


	return 0;
}