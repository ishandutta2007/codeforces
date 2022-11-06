#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > a;
vector<int> p, sz;
vector<bool> vis;
int Find(int x) 
{
	if (p[x] == x) return x;
	else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
	int x1 = Find(x), y1 = Find(y);
	p[x1] = y1;
	sz[y1] += sz[x1];
}

bool Connected(int x, int y) 
{
	return Find(x) == Find(y);
}

int main()
{
    int T;
	scanf("%d", &T);
	while (T --) 
    {
		scanf("%d", &n);

		p.clear(); p.resize(n + 1, 0);
		a.clear();
		sz.clear(); sz.resize(n + 1, 1);
		vis.clear(); vis.resize(n + 1, false);
		int in;
		for (int i = 0; i < n; i ++) 
        {
			scanf("%d", &in);
			a.emplace_back(in, i + 1);
			p[i+1] = i+1;
		}
		sort(a.begin(), a.end()); 
        reverse(a.begin(), a.end());
		vector<int> ans;
		ans.resize(n + 1);
		for (int i = 0; i < n; i ++) 
        {
			int x = a[i].second;
			if (!vis[x])
            {
				for (int j = 0; j < a[i].first; j++) 
                {
					printf("? %d\n", x);
					fflush(stdout);
					scanf("%d", &in);
					if (!Connected(in, x)) 
                    {
						Union(in, x);
						vis[in] = true;
						if (sz[Find(x)] > j + 2) break;
					}
				}
			}
		}
		printf("!");
		for (int i = 1; i <= n; i ++) 
			printf(" %d", Find(i));
		printf("\n");
		fflush(stdout);
	}
	return 0;
}