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

const int maxn = 210000;

int tn,n,k,m;
int c[maxn];
ll al,ans;
struct node{int num,x;}a[maxn];

int fa[maxn];
int findfa(const int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}

int main()
{
	scanf("%d%d%d",&n,&k,&m); al+=(ll)n*m;
	//bool flag=false; if(n==100000&&k==1000000000&&m==1000000000) flag=true;
	tn=0;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		if(x==a[tn].x) a[tn].num++;
		else a[++tn]=(node){1,x};
	}
	n=tn; for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=n;i++) if(a[i].num>=k)
	{
		int temp=a[i].num/k;
		a[i].num%=k; ans+=(ll)temp*k*m;
		if(!a[i].num)
		{
			fa[i]=i-1;
			int lj=findfa(i-1),rj;
			for(rj=i+1;rj<=n&&lj>=1&&a[lj].x==a[rj].x;rj++,lj=findfa(lj))
			{
				int kk=a[lj].num+a[rj].num;
				ans+=(ll)kk/k*k*m;
				kk%=k;
				a[lj].num=0; fa[lj]=lj-1;
				a[rj].num=kk;
				if(kk) {i=rj-1;break;}
				fa[rj]=rj-1;
			}
		}
	}
	tn=0; 
	for(int i=1;i<=n;i++) if(a[i].num) 
	{
		if(a[i].x==a[tn].x) a[tn].num+=a[i].num;
		else a[++tn]=a[i];
	}
	n=tn;
	
	if(m==1) return printf("%I64d\n",al-ans),0;
	
	int l=1,r=n;
	//if(flag) printf("%d %I64d\n",n,al-ans);
	while(l<=r&&a[l].x==a[r].x)
	{
		if(l+1>=r)
		{
			ll temp;
			if(l==r) temp=(ll)m*a[l].num;
			else  temp=(ll)m*(a[l].num+a[r].num);
			
			if(temp%k) ans+=temp/k*k;
			else ans=al;
			break;
		}
		ll temp=(a[l].num+a[r].num);
		ans+=(ll)temp/k*k*(m-1);
		temp%=k;
		if(temp) break;
		l++,r--;
	}
	printf("%I64d\n",al-ans);
	
	return 0;
}