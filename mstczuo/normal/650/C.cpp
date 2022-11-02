# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstring>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;

typedef long long ll;

const int maxn = 1000010;

vector<int> g[maxn];
vector<int> e[maxn];

int a[maxn];
int p[maxn];
int c[maxn];

bool v[maxn];

int n, m;

#define A(i, j) a[((i) * m + (j))]

int k;
bool cmp1(int i,int j) { return A(k,i) < A(k,j); }
bool cmp2(int i,int j) { return A(i,k) < A(j,k); }
bool cmp3(int i,int j) { return a[i] < a[j]; }

vector<int> S;
void BFS(int s) {
	S.clear(); S.push_back(s);
	queue<int> q; q.push(s);
	v[s] = true;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int y:e[x]) if(!v[y]) {
			v[y] = true; S.push_back(y); q.push(y);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i * m + j]);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) p[j] = j;
		k = i;
		sort(p, p + m, cmp1);
		for(int j = 1; j < m; ++j) 
			if(A(k,p[j]) > A(k,p[j-1])) {
				g[k * m + p[j]].push_back(k * m + p[j-1]);
			} else {
				e[k * m + p[j]].push_back(k * m + p[j-1]);
				e[k * m + p[j-1]].push_back(k * m + p[j]);
			}
	}
	for(int j = 0; j < m; ++j) {
		for(int i = 0; i < n; ++i) p[i] = i;
		k = j;
		sort(p, p + n, cmp2); 
		for(int i = 1; i < n; ++i)
			if(A(p[i],k) > A(p[i-1],k)) {
				g[p[i] * m + k].push_back(p[i-1] * m + k);
			} else {
				e[p[i] * m + k].push_back(p[i-1] * m + k);
				e[p[i-1] * m + k].push_back(p[i] * m + k);
			}
	}
//	for(int i = 0; i < n * m; ++i) {
//		for(int x:g[i]) printf("a[%d] > a[%d]\n", i, x);
//		for(int x:e[i]) printf("a[%d] = a[%d]\n", i, x);
//	}
	for(int i = 0; i < n * m; ++i) p[i] = i;
	sort(p, p + n * m, cmp3);
	for(int i = 0; i < n * m; ++i) if(!v[p[i]]) {
		BFS(p[i]);

//		printf("Set = {");
//		for(int x:S) printf("%d ", x);
//		printf("} Restrict = {");
//		for(int x:S) for(int y:g[x]) printf("%d ", y);
//		puts("}");

		int val = 1;
		for(int x:S) for(int y:g[x]) val = max(val, c[y] + 1);
		for(int x:S) c[x] = val;
	}
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			printf("%d%c", c[i * m + j], " \n"[j==m-1]);
	return 0;
}