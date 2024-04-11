#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;
typedef complex<ld> point;

const int oo = 0x3f3f3f3f;
const ld eps = 1e-12;
const int maxn = 100010;

struct sset{
	map<int,int> freq;
	int maxfreq;
	int64 sum;

	void insert(int v){
		int cfreq = ++freq[v];

		if (cfreq > maxfreq){
			maxfreq = cfreq;
			sum = v;
		}
		else if (cfreq == maxfreq){
			sum += v;
		}
	}

	void insert(sset *s){
		for (auto v : s->freq){
			int cfreq = freq[v.first] += v.second;

			if (cfreq > maxfreq){
				maxfreq = cfreq;
				sum = v.first;
			}
			else if (cfreq == maxfreq)
				sum += v.first;
		}
	}

	int weight(){
		return freq.size();
	}
};

sset *node[maxn];
int64 ans[maxn];
int col[maxn];
vi adj[maxn];

void dfs(int s, int f){
	int bigchild = -1;

	for (auto c : adj[s]) if (c != f){
		dfs(c, s);
		if (bigchild == -1 || node[c]->weight() > node[bigchild]->weight())
			bigchild = c;
	}

	if (bigchild != -1) node[s] = node[bigchild];
	else node[s] = new sset();

	for (auto c : adj[s]) if (c != f && c != bigchild){
		node[s]->insert(node[c]);
		node[c]->freq.clear();
		free(node[c]);
	}

	node[s]->insert(col[s]);
	ans[s] = node[s]->sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &col[i]);

	for (int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	for (int i = 1; i <= n; ++i)
		printf("%I64d ", ans[i]);
	putchar('\n');

	return 0;
}