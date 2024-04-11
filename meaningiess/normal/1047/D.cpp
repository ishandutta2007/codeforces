#include<iostream>
using namespace std;
long long ans=0,n,m,res=0;
long long chk1(long long x)
{
	return x-(x%6)+(x%6==4?2:0)+(x%6==5?4:0);
}
long long chk3(long long x)
{
	if (x==1) return 0;
	if (x==2) return 4;
	return x*3-(x%2);
}
long long chk5(long long x)
{
	if (x==1) return 4;
	return x*5-(x%2);
}
long long chk2(long long x)
{
	if (x==1 || x==2) return 0;
	if (x==3) return 4;
	if (x==7) return 12;
	return x*2;
}
long long chk4(long long x)
{
	if (x==1) return 2;
	return x*4;
}
int main()
{
	cin>>n>>m;ans+=(n/6)*m*6;
	if (n%6==1) ans+=chk1(m);
	if (n%6==2) ans+=chk2(m);
	if (n%6==3) ans+=chk3(m);
	if (n%6==4) ans+=chk4(m);
	if (n%6==5) ans+=chk5(m);
	
	swap(n,m);res+=(n/6)*m*6;
	if (n%6==1) res+=chk1(m);
	if (n%6==2) res+=chk2(m);
	if (n%6==3) res+=chk3(m);
	if (n%6==4) res+=chk4(m);
	if (n%6==5) res+=chk5(m);
	cout<<max(ans,res);
}