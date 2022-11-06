#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (300000)


int n;
vector<int>e[N];
bool used[N];
long long a[N];
long long b[N];
long long c[N];


void init(void){
	memset(used, 0, sizeof(used));
	return;
}

long long dfs(int k,int pk,int ppk){
	used[k] = true;
	long long sv = 0;
	long long svc = 0;
	long long nv;
	long long s;
	vector<long long>v;
	vector<long long>vb;
	vector<long long>vc;
	f(i, e[k].size()){
		if (!used[e[k][i]]){
			nv = dfs(e[k][i], k, pk);
			v.push_back(nv);
			sv += nv;
			a[k] += a[e[k][i]];
			vb.push_back(b[e[k][i]]);
			svc += c[e[k][i]];
			vc.push_back(c[e[k][i]]);
			b[k]++;
			c[k]++;
		}
	}
	s= (sv*sv);
	svc = svc*svc;
	f(i, v.size()){
		a[k] += ((sv - v[i])*vb[i]);
		s -= (v[i] * v[i]);
		svc -= (vc[i] * vc[i]);
	}
	s = s / 2;
	svc = svc / 2;
	a[k] += s;
	a[k] += b[k];
	a[k] -= svc;

	sv++;
	if (ppk != -1){
		b[ppk] += (b[k] + sv);
		c[ppk] += c[k];
	}
	return sv;
}

int main(void){
	int x, y;
	scanf("%d", &n);
	init();
	f(i, n-1){
		scanf("%d %d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	f(i, N){
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	dfs(0, -1, -1);


	printf("%I64d\n", a[0]);

	return 0;
}