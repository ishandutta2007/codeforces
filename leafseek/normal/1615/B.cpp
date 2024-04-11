#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
inline int F(const int x,const int I)
{
	int Sum=((x>>(I+1))<<I);
	Sum+=max(0,(x&((1<<(I+1))-1))-((1<<I)-1));
	return Sum;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int l,r;
	while(T--)
	{
		cin>>l>>r;
		int Ans=0;
		rep(I,0,20)
			Ans=max(Ans,(F(r,I)-F(l-1,I)));
		Ans=((r-l+1)-Ans);
		cout<<Ans<<'\n';
	}
	return 0;
}