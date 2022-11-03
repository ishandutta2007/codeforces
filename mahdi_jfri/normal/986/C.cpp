#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxb = 22;
const int maxn = (1 << maxb) + 10;

int topol[maxn] , sz , n , color[maxn] , c = 1;

bool is[maxn] , visited[maxn];

void dfs(int v)
{
	visited[v] = 1;

	int sm = (1 << n) - 1 - v;
	if(is[v] && !visited[sm])
		dfs(sm);

	for(int i = 0; i < n; i++)
		if(bit(v , i) && !visited[v ^ (1 << i)])
			dfs(v ^ (1 << i));

	topol[sz] = v;
	sz--;
}

void sfd(int v)
{
	color[v] = c;
	
	int sm = (1 << n) - 1 - v;
	if(is[sm] && !color[sm])
		sfd(sm);

	for(int i = 0; i < n; i++)
		if(!bit(v , i) && !color[v ^ (1 << i)])
			sfd(v ^ (1 << i));
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);

	sz = (1 << n) - 1;

	int a;
	for(int i = 0; i < m; i++)
		scanf("%d", &a) , is[a] = 1;

	for(int i = 0; i < (1 << n); i++)
		if(!visited[i])
			dfs(i);

	for(int i = 0; i < (1 << n); i++)
		if(!color[topol[i]])
			sfd(topol[i]) , c++;

	memset(visited , 0 , sizeof visited);

	int res = 0;
	for(int i = 0; i < (1 << n); i++)
		if(is[i] && !visited[color[i]])
		{
			visited[color[i]] = 1;
			res++;
		}

	cout << res << endl;

}