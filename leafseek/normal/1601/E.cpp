#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=300000+5,Bit=19;
struct SparseTable_List
{
	const int *ini;
	int Log_2[MaxN],Min[Bit+1][MaxN];
	inline int Compare(const int u,const int v)
		{return ((ini[u]<=ini[v])?u:v);}
	inline void Initalize(const int n)
	{
		Log_2[0]=(-1);
		rep(i,1,n)
			Log_2[Min[0][i]=i]=(Log_2[i>>1]+1);
		rep(lv,1,Bit)
			rep(i,1,n-(1<<lv)+1)
				Min[lv][i]=Compare(Min[lv-1][i],Min[lv-1][i+(1<<(lv-1))]);
	}
	inline int Query(const int lef,const int rig)
	{
		const int lv=Log_2[rig-lef+1];
		return Compare(Min[lv][lef],Min[lv][rig-(1<<lv)+1]);
	}
};
SparseTable_List StA,StC;
int arr[MaxN],pit[MaxN],cum[MaxN],the[MaxN];
long long Sum[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m,q,k;
	cin>>n>>q>>k,m=0;
	rep(i,1,n)
		cin>>arr[i];
	StA.ini=arr,StA.Initalize(n);
	int I=0;
	rep(i,1,k)
		for(int j=i;j<=n;j+=k)
			pit[j]=(++I);
	rep(i,1,n)
		cum[pit[i]]=arr[StA.Query(i,min(i+k,n))];
	dow(i,n,1)
	{
		while(m&&cum[i]<=cum[the[m]]) --m;
		if(the[m])
			Sum[i]=(Sum[the[m]]+((the[m]-i)*(long long)cum[i]));
		the[++m]=i;
	}
	StC.ini=cum,StC.Initalize(n);
	int lef,rig;
	while(q--)
	{
		cin>>lef>>rig;
		long long Record=arr[lef];
		if((rig-lef)>=k)
		{
			const int u=pit[lef],v=(pit[lef+(((rig-lef)/k)*k)]-1),x=StC.Query(u,v);
			Record+=((Sum[u]-Sum[x])+((v-x+1)*(long long)cum[x]));
		}
		cout<<Record<<'\n';
	}
	return 0;
}