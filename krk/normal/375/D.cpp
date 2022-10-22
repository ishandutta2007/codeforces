#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxt = 317;

int n, m;
int col[Maxn];
vector <int> neigh[Maxn];
map <int, int> M[Maxn];
int BIT[Maxt][Maxn];
int curb;
int myM[Maxn], myBIT[Maxn];
vector <ii> myQ[Maxn];
int res[Maxn];

void Insert(int BIT[], int x, int val)
{
	for (int i = x; i > 0; i -= i & -i)
		BIT[i] += val;
}

int Get(int BIT[], int x)
{
	int res = 0;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

void Union(int aM, int aBIT, int bM, int bBIT, int &cM, int &cBIT)
{
	if (M[aM].size() < M[bM].size()) { swap(aM, bM); swap(aBIT, bBIT); }
	bool flag = false;
	if (aBIT == -1) {
		for (map <int, int>::iterator it = M[bM].begin(); it != M[bM].end(); it++)
			M[aM][it->first] += it->second;
		if (M[aM].size() > Maxt) {
			for (map <int, int>::iterator it = M[aM].begin(); it != M[aM].end(); it++)
				Insert(BIT[curb], it->second, 1);
			curb++; flag = true;
		}
	} else for (map <int, int>::iterator it = M[bM].begin(); it != M[bM].end(); it++) {
				map <int, int>::iterator it2 = M[aM].find(it->first);
				if (it2 != M[aM].end()) {
					Insert(BIT[aBIT], it2->second, -1);
					it2->second += it->second; Insert(BIT[aBIT], it2->second, 1);
				} else {
					M[aM][it->first] = it->second; Insert(BIT[aBIT], it->second, 1);
				}
			}
	M[bM].clear();
	cM = aM; cBIT = flag? curb - 1: aBIT;
}

void Traverse(int v, int p)
{
	M[v][col[v]]++;
	vector <ii> seq;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		seq.push_back(ii(M[myM[u]].size(), u));
	}
	sort(seq.begin(), seq.end());
	for (int i = int(seq.size()) - 1; i >= 0; i--)
		Union(myM[v], myBIT[v], myM[seq[i].second], myBIT[seq[i].second], myM[v], myBIT[v]);
	if (myBIT[v] == -1)
		for (int i = 0; i < myQ[v].size(); i++) {
			int got = 0;
			for (map <int, int>::iterator it = M[myM[v]].begin(); it != M[myM[v]].end(); it++)
				if (it->second >= myQ[v][i].first) got++;
			res[myQ[v][i].second] = got;
		}
	else for (int i = 0; i < myQ[v].size(); i++)
			res[myQ[v][i].second] = Get(BIT[myBIT[v]], myQ[v][i].first);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &col[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int v, k; scanf("%d %d", &v, &k);
		myQ[v].push_back(ii(k, i));
	}
	for (int i = 1; i <= n; i++) {
		myM[i] = i; myBIT[i] = -1;
		sort(myQ[i].begin(), myQ[i].end());
	}
	Traverse(1, 0);
	for (int i = 0; i < m; i++)
		printf("%d\n", res[i]);
	return 0;
}