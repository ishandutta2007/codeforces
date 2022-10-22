#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5;
inline int Query(const int x)
{
	// x >= 2
	cout<<"? "<<(x-1)<<endl;
	int y;
	cin>>y;
	return y;
}
signed main()
{
	int n;
	cin>>n;
	// a[i] >= 2
	int Beg=2,End=(n*2001),Mid;
	while(Beg<End)
	{
		Mid=((Beg+End)>>1);
		if(Query(Mid)==1) End=Mid;
		else Beg=(Mid+1);
	}
	const int Lim=Beg;
	int Answer=(Lim-1);
	rep(i,2,n)
	{
		const int x=((Lim+i-1)/i);
		if(Query(x)==i)
			Answer=min(Answer,(x-1)*i);
	}
	cout<<"! "<<Answer<<'\n';
	return 0;
}