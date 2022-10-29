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
#define inf 1e9
using namespace std;

const int maxn = 110000;
const int maxk = 1100;
const int maxv = 26;

char str[maxn],s[110];
int n,m,L,R;
int las[maxv][maxn],col[maxv];
int f[maxn];
struct node
{
	int l,r;
	node(){}
	node(const int _l,const int _r){l=_l;r=_r;}
}a[maxv][maxk]; int cnt[maxv];

ll ans;

int main()
{
	scanf("%s",str); n=strlen(str);
	scanf("%d%d%d",&m,&L,&R);
	int ev=0;
	for(int i=1;i<=m;i++)
	{
		int l,r; scanf("%s%d%d",s,&l,&r);
		const int w=s[0]-'a';
		a[w][++cnt[w]]=node(l,r);
		if(l==0) ev++;
	}
	for(int i=0;i<26;i++) las[i][col[i]=0]=-1;
	
	int now=0;
	for(int i=0;i<n;i++)
	{
		f[i]=ev; if(f[i]>=L&&f[i]<=R) now++;
		const int w=str[i]-'a';
		las[w][++col[w]]=i;
		for(int j=1;j<=cnt[w];j++)
		{
			if(col[w]>=a[w][j].l)
			{
				for(int k=las[w][max(0,col[w]-a[w][j].l)]+1;k<=las[w][col[w]-a[w][j].l+1];k++)
				{
					f[k]++;
					if(f[k]==L) now++;
					if(f[k]==R+1) now--;
				}
			}
			if(col[w]>a[w][j].r)
			{
				for(int k=las[w][col[w]-a[w][j].r-1]+1;k<=las[w][col[w]-a[w][j].r];k++)
				{
					f[k]--;
					if(f[k]==R) now++;
					if(f[k]==L-1) now--;
				}
			}
		}
		
		ans+=(ll)now;
	}
	printf("%I64d\n",ans);
	
	return 0;
}