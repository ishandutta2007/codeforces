# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int c[200],s[200],sum,F[2][10010];
int *f = F[1], *g = F[0];
int main()
{	
	int n, m, t;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%d", &t);
		for(int i=1; i<=t; i++) scanf("%d", &c[i]);
		int sum = 0;
		for(int i=1; i<=t; i++) s[i] = 0;
		for(int i=1; i<=t; i++) sum += c[i];
		for(int i=1; i<=t; i++) c[i] += c[i-1];
		for(int k=1; k<t; k++)
			for(int i=k; i<=t; i++)
				s[t-k] = max(s[t-k], sum - (c[i]-c[i-k]));
		s[t] = sum;
		
		memset(f,0,sizeof(f));
		for(int i=1; i<=m; i++) f[i] = g[i];
		for(int k=1; k<=t; k++)
			for(int i=m-k; i>=0; i--)
				f[i+k] = max(f[i+k], g[i] + s[k]);
		swap(f,g);
	}
	cout << g[m] << endl;
	return 0;
}