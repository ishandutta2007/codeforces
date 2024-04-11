#include<bits/stdc++.h>
using namespace std;

const int N = 305;
const int inf = INT_MAX/2;
typedef vector<int> vi;
typedef vector<vi> matrix;

matrix operator * (matrix a,matrix b)
{
	int m = a.size(),n = a[0].size(),p = b[0].size();
	matrix c(m,vi(p,-inf));
	for(int i = 0;i < m;++i)for(int j = 0;j < p;++j)
	for(int k = 0;k < n;++k)c[i][j] = max(c[i][j] ,a[i][k] + b[k][j]);
	return c;
}

int main()
{
	int n,m;
	cin >> n >> m;
	matrix dist[20];
	dist[0].assign(n, vi(n,-inf));
	for(int i = 0;i < n;++i)dist[0][i][i] = 0;
	while(m--)
	{
		int u,v,uv,vu;
		cin >> u >> v >> uv >> vu;
		dist[0][u-1][v-1] = uv;
		dist[0][v-1][u-1] = vu;
	}
	for(int i = 1;i < 17;++i) dist[i] = dist[i-1] * dist[i-1];
	int pos = 1;
	matrix cur = dist[0];
	for(int i = 16;i >= 0;--i){
		matrix tem = cur * dist[i];
		bool flag = 0;
		for(int j = 0; j < n;++j)if(tem[j][j] > 0)flag = 1;
		if(!flag)pos += (1 << i), cur = tem;
		}
	cur = cur * dist[0];
	for(int i = 0;i < n ;++i)if(cur[i][i] > 0) return cout << pos + 1,0;
	cout<< 0 <<endl;
}