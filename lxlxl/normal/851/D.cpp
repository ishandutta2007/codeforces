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
#define lowbit(x) x&(-x)
using namespace std;

inline void read(int &x)
{
	char c;
	while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 3000003;

int u;
int p[maxn],pri;
ll re[maxn];
bool v[maxn];
void prepare()
{
	for(int i=2;i<=u;i++)
	{
		if(!v[i]) p[++pri]=i;
		for(int j=1,k=i*p[j];k<=u&&j<=pri;j++,k=i*p[j])
		{
			v[k]=true;
			if(i%p[j]==0) break;
		}
	}
}

int n,c1,c2;
int a[maxn];

int s[maxn];
ll si[maxn];

int main()
{
	read(n); read(c2); read(c1);
	for(int i=1;i<=n;i++)
	{
		read(a[i]); s[a[i]]++; si[a[i]]+=(ll)a[i];
		if(a[i]>u) u=a[i];
	}
	u+=100; prepare(); u+=p[pri];
	for(int i=1;i<=u;i++) s[i]+=s[i-1];
	for(int i=1;i<=u;i++) si[i]+=si[i-1];
	
	int k=c2/c1; if(c2%c1!=0) k++;
	for(int i=1;i<=pri;i++)
	{
		for(int j=p[i];j<=u;j+=p[i]) 
		{
			int dj=j-p[i]+1;
			if(k<p[i])
			{
				re[i]+=(ll)(s[j-k]-s[dj-1])*c2;
				dj=j-k+1;
			}
			re[i]+=((ll)(s[j]-s[dj-1])*j-(si[j]-si[dj-1]))*(ll)c1;
		}
	}
	ll ans=LLONG_MAX;
	for(int i=1;i<=pri;i++) if(ans>re[i]) ans=re[i];
	printf("%I64d\n",ans);
	
	return 0;
}