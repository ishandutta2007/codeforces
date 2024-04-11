#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> V[3];
vector <int> a, b;

int Find(int id, int val)
{
	for (int i = 0; i < V[id].size(); i++)
		if (V[id][i] == val) return i;
	return V[id].size();
}

void Traverse(int l, int r, int ind, int flip)
{
	if (ind == V[l].size()) return;
	int v = V[l][ind];
	int nind = ind + 1;
	while (nind < V[l].size() && v == V[l][nind]) nind++;
	int u = nind < V[l].size()? V[l][nind]: -1;
	int m = 3 - l - r;
	if (!flip) 
		if (nind == V[l].size()) {
			for (int i = nind - 1; i > ind; i--) { a.push_back(l); b.push_back(m); }
			a.push_back(l); b.push_back(r);
			for (int i = ind + 1; i < nind; i++) { a.push_back(m); b.push_back(r); }
			for (nind--; nind >= ind; nind--) { V[r].push_back(V[l].back()); V[l].pop_back(); }
			return;
		} else if (ind + 1 != nind) { 
					Traverse(l, r, nind, 1); 
					Traverse(l, m, ind, 1); 
					Traverse(r, l, Find(r, u), 1); 
					Traverse(m, r, Find(m, v), 1); 
					Traverse(l, r, Find(l, u), 0); 
					return;  
				} else { Traverse(l, r, ind, 1); return; }
	Traverse(l, m, nind, 1);
	for (nind--; nind >= ind; nind--) { a.push_back(l); b.push_back(r); V[r].push_back(V[l].back()); V[l].pop_back(); }
	Traverse(m, r, Find(m, u), 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d; scanf("%d", &d);
		V[0].push_back(d);
	}
	Traverse(0, 2, 0, 0);
	printf("%d\n", a.size());
	for (int i = 0; i < a.size(); i++)
		printf("%d %d\n", a[i] + 1, b[i] + 1);
	return 0;
}