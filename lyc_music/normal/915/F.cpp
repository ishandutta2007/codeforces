//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int n,a[N],f[N],cnt[N],ans;

struct edg
{
	int s,t,mx,mn;
}e[N<<1];

bool Cmp1(edg x,edg y)
{
	return x.mx<y.mx;
}

bool Cmp2(edg x,edg y)
{
	return x.mn>y.mn;
}

int gf(int k)
{
	return (f[k]==k)?k:f[k]=gf(f[k]);
}

void merge(int x,int y)
{
	cnt[gf(x)]+=cnt[gf(y)];
	f[gf(y)]=gf(x);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		e[i].s=read(),e[i].t=read();
		e[i].mx=max(a[e[i].s],a[e[i].t]);
		e[i].mn=min(a[e[i].s],a[e[i].t]);
	}
	sort(e+1,e+n,Cmp1);
	for (int i=1;i<=n;i++) cnt[i]=1,f[i]=i;
	for (int i=1;i<n;i++)
	{
		ans+=e[i].mx*cnt[gf(e[i].s)]*cnt[gf(e[i].t)];
		merge(e[i].s,e[i].t);
	}
	sort(e+1,e+n,Cmp2);
	for (int i=1;i<=n;i++) cnt[i]=1,f[i]=i;
	for (int i=1;i<n;i++)
	{
		ans-=e[i].mn*cnt[gf(e[i].s)]*cnt[gf(e[i].t)];
		merge(e[i].s,e[i].t);
	}
	writeln(ans);
}