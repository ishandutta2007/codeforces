#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
long long maxx(long long x,long long y)
{
	return x>y?x:y;
}
long long a[10005];long long maxn=0,last[10005];
int main()
{
	int m,b;
	cin>>m>>b;
	for(int i=b;i>=0;i--)
	{
		a[i]=(b-i)*m;
		//a[i]++;
		//cout<<a[i]<<" ";
	}
//	cout<<endl;
	maxn=((1+b)*b)/2;
	last[b]=maxn;
	for(int i=b-1;i>=0;i--)
	{
		last[i]=last[i+1]-((a[i+1]+1)*(i+1))-((1+a[i+1])*a[i+1])/2+(((a[i+1]+1+a[i])*(a[i]-a[i+1]))/2)*(i+1)+(((1+i)*i)/2)*(a[i]-a[i+1]);
		//cout<<last[i+1]<<" "<<((a[i+1]+1)*(i+1))<<" "<<((1+a[i+1])*a[i+1])/2<<" "<<(((a[i+1]+1+a[i])*(a[i]-a[i+1]))/2)*i<<" "<<(((1+i)*i)/2)*(a[i]-a[i+1])<<endl;
		maxn=maxx(last[i],maxn);
	}
	cout<<maxn;
}