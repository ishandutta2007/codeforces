//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
long long l,r,st,t,x,y;set<long long>s;
int main()
{
	read(st),read(l),read(r),read(t),read(x),read(y);
	if(x>y)
	{
		if((x-y<2e18/t&&st-l>=t*(x-y))&&st+y<=r) puts("Yes");
		else if(x-y<2e18/t&&st-l>=t*x-(t-1)*y) puts("Yes");
		else puts("No");
		return 0;
	}
	long long qwq=st,tp;qwq=l+(qwq-l)%x,t-=(st-qwq)/x;
	if(t<=0) return puts("Yes"),0;else if(qwq+y>r) return puts("No"),0;
	while(t>0)
	{
		qwq+=y;if(qwq>r) return puts("No"),0;else tp=qwq,qwq=l+(qwq-l)%x,t-=(tp-qwq)/x;
		if(t<=0) return puts("Yes"),0;else if(s.count(qwq)) return puts("Yes"),0;else s.insert(qwq);
	}
	return puts("Yes"),0;
}