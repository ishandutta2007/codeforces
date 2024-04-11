#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5;
int a[MaxN],b[MaxN],c[MaxN],d[MaxN],e[MaxN],E[MaxN],f[MaxN],F[MaxN],
	g[MaxN],h[MaxN],u[MaxN],r[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m,k;
	rep(TT,1,T)
	{
		cin>>n>>m;
		rep(i,1,n*m)
			cin>>a[i],b[i]=a[i],c[i]=d[i]=e[i]=f[i]=g[i]=h[i]=r[i]=0;
		sort(b+1,b+n*m+1);
		rep(i,1,n*m)
		{
			d[i]=(upper_bound(b+1,b+n*m+1,a[i])-b)-1;
			a[i]=(lower_bound(b+1,b+n*m+1,a[i])-b);
		}
		rep(i,1,n*m)
		{
			if(g[a[i]]) continue;
			g[a[i]]=true;
			const int A=(a[i]-1)/m,D=(d[i]-1)/m;
			if(A==D) continue;
			f[a[i]]=(d[i]-1)%m+1,e[a[i]]=d[i]-f[a[i]],h[a[i]]=true;
			F[a[i]]=d[i]-f[a[i]]-((A+1)*m),E[a[i]]=(A+1)*m;
		}
		dow(i,n*m,1)
		{
			if(h[a[i]])
			{
				const int A=a[i];
				++c[a[i]],a[i]=(e[a[i]]+c[a[i]]),r[a[i]]=i;
				if(c[A]==f[A])
				{
					u[A]=true,h[A]=false;
					c[A]=0;
				}
				continue;
			}
			else if(u[a[i]])
			{
				const int A=a[i];
				if(!F[A])
				{
					u[A]=false;
					c[A]=0;
					++c[a[i]],a[i]+=c[a[i]],--a[i],r[a[i]]=i;
					continue;
				}
				++c[a[i]],a[i]=(E[a[i]]+c[a[i]]),r[a[i]]=i;
				if(c[A]==F[A])
				{
					u[A]=false;
					c[A]=0;
				}
				continue;
			}
			++c[a[i]],a[i]+=c[a[i]],--a[i],r[a[i]]=i;
		}
		int Sum=0;
		for(int i=0;i<n*m;i+=m)
			rep(I,1,m-1)
				rep(J,I+1,m)
					if(r[i+I]<r[i+J])
						++Sum;
		cout<<Sum<<endl;
	}
	return 0;
}