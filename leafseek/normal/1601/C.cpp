#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=(1<<21)+5;
int a[MaxN],b[MaxN],y[MaxN],c[MaxN],x[MaxN];
int k[MaxN],p[MaxN];
struct TreeArray
{
	int s[MaxN];
	inline void Insert(const int pos)
	{
		for(int i=pos;i<(1<<21);i+=(i&(-i)))
			++s[i];
	}
	inline void Delete(const int pos)
	{
		for(int i=pos;i<(1<<21);i+=(i&(-i)))
			--s[i];
	}
	inline int Query(const int pos)
	{
		int S=0;
		for(int i=pos;i;i^=(i&(-i)))
			S+=s[i];
		return S;
	}
};
TreeArray Tr;
inline long long calc(const int n)
{
	rep(i,1,n) x[i]=c[i];
	sort(x+1,x+n+1);
	rep(i,1,n) c[i]=(lower_bound(x+1,x+n+1,c[i])-x);
	long long Sum=0;
	rep(i,1,n)
	{
		Sum+=((i-1)-Tr.Query(c[i]));
		Tr.Insert(c[i]);
	}
	rep(i,1,n)
		Tr.Delete(c[i]);
	return Sum;
}
inline void Solve_Position(const int lef,const int rig,const int his,const int fut)
{
	if(lef>rig) return;
	const int mid=(lef+rig)>>1;
	rep(i,his+1,fut)
	{
		k[i]=0;
		if(a[i]<b[mid]) k[i]=(+1);
		if(a[i]>b[mid]) k[i]=(-1);
	}
	p[his]=0;
	rep(i,his+1,fut) p[i]=(p[i-1]+k[i]);
	int tim=his;
	rep(i,his+1,fut)
		if(p[i]>p[tim]) tim=i;
	y[mid]=tim;
	Solve_Position(lef,mid-1,his,tim);
	Solve_Position(mid+1,rig,tim,fut);
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		rep(i,1,n)
			cin>>a[i];
		rep(i,1,m)
			cin>>b[i];
		sort(b+1,b+m+1);
		Solve_Position(1,m,0,n);
		int j=1,I=0;
		rep(i,0,n)
		{
			if(i) c[++I]=a[i];
			while((j<=m)&&y[j]==i)
				c[++I]=b[j++];
		}
		cout<<calc(n+m)<<endl;
	}
	return 0;
}