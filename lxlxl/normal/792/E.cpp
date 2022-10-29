#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 510;
const int maxm = 51000;

int n;

int a[2][maxm*20],now,len[2];
int c[maxn];

int main()
{
		scanf("%d",&n);
		len[now=0]=0;
		
		int x; scanf("%d",&x); c[1]=x;
		int l,r;
		for(l=1;l<=x;l=r+1)
		{
			r=x/(x/l);
			int x1=r,x2=(x%r==0?r-1:0)*(l!=r?1:0);
			if(x2) a[now][++len[now]]=x2;
			a[now][++len[now]]=x1;
		}
		
		for(int i=2;i<=n;i++)
		{
			len[now=!now]=0;
			
			scanf("%d",&x); c[i]=x;
			int pos=1;
			for(l=1;l<=x;l=r+1)
			{
				r=x/(x/l);
				int x1=r,x2=(x%r==0?r-1:0)*(l!=r?1:0);
				while(pos<=len[!now]&&a[!now][pos]<=r)
				{
					if(x1==a[!now][pos]) a[now][++len[now]]=x1;
					if(x2==a[!now][pos]) a[now][++len[now]]=x2;
					pos++;
				}
			}
		}
		int ans=a[now][len[now]]; ll ansn=0;
		for(int i=1;i<=n;i++) 
		{
			int tmp;
			if(c[i]<=ans+1) tmp=1;
			else tmp=c[i]/(ans+1)+(c[i]%(ans+1)!=0?1:0);
			ansn+=tmp;
		}
		printf("%I64d\n",ansn);
	
	return 0;
}