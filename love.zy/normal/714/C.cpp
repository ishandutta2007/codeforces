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
#define lowbit(x) (x&(-x))
  
int tot[300005];
int er[20];
int i,j,n;
char c;
char s[20];
LL x,y,k,l,m;

int main()
{
	scanf("%d\n",&n);
	for(i=1,er[0]=1;i<=20;i++)er[i]=er[i-1]*2;
	for(i=1;i<=n;i++)
	{
		scanf("%c ",&c);
		if(c=='+')
		{
			scanf("%lld\n",&m);
			l=0;k=0;
			while(m>0)
			{
				x=m%10;
				l+=(er[k++])*(x%2);
				m=m/10;
			}
			tot[l]++;
			continue;
		}
		if(c=='-')
		{
			scanf("%lld\n",&m);
			l=0;k=0;
			while(m>0)
			{
				x=m%10;
				l+=(er[k++])*(x%2);
				m=m/10;
			}
			tot[l]--;
			continue;
		}
		if(c=='?')
		{
			scanf("%s\n",s);
			m=strlen(s);l=0;
			for(j=m-1;j>=0;j--)l+=(s[j]-48)*er[m-j-1];
			printf("%d\n",tot[l]);
		}
	}
    return 0;
}