#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define sz(x) ((int) (x).size())
#define db(x) cout << #x" = " << x << endl
#define db2(x,y) cout << #x" = " << x << "; " << #y" = " << y << endl
#define db3(x,y,z) cout << #x" = " << x << "; " << #y" = " << y << "; " << #z" = " << z << endl
#define X first
#define Y second
const int N = 2005;
bitset<N> Mp[N];
bitset<N> repr[N];
int rownum[N];
int n,m;
int qa[500005], qb[500005];
void printall()
{
	for (int i = 0; i < n; i++,cout << endl)
	{
	   for (int j  =0; j < n; j++) printf("%d", (int)Mp[i][j]);
	   cout << ' ';
	   for (int j  =0; j < n; j++) printf("%d", (int)repr[i][j]);
	}
}
int main()
{
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) Mp[i].reset(), repr[i].reset();
	for (int i = 0; i < m; i++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		Mp[a][b] = 1;
		qa[i] = a; qb[i] = b;
	}
	
	
	for (int i = 0; i < n; i++) repr[i][i] = 1;
	for (int i = 0; i < n; i++) 
	{
		int ci = -1;
		for (int j = 0; j < n; j++) if (Mp[j][i] == 1) ci = j;
		assert(ci != -1);
		swap(Mp[i],Mp[ci]);
		swap(repr[i],repr[ci]);
		
		for (int j = 0; j < n; j++)
		   if (i != j && Mp[j][i]) 
		   {
			   Mp[j] ^= Mp[i];
			   repr[j] ^= repr[i];
		   }
	}
	for (int i = 0; i < m; i++) 
	{
		if (repr[qb[i]][qa[i]] == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}