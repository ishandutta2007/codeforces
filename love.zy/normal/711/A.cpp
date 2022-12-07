#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

char s[1005][10];
bool f;
int i,j,k,l,m,n;

int main()
{
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)gets(s[i]);
	f=false;
	for(i=1;i<=n;i++)
	{
		if(s[i][0]=='O' && s[i][1]=='O')
		{
			f=true;
			s[i][0]=s[i][1]='+';
			break;
		}
		if(s[i][3]=='O' && s[i][4]=='O')
		{
			f=true;
			s[i][3]=s[i][4]='+';
			break;
		}
	}
	if(f)printf("YES\n");else printf("NO\n");
	if(f)
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=4;j++)printf("%c",s[i][j]);
			printf("\n");
		}
    return 0;
}