#include<iostream>
using namespace std;
string s="What are you doing at the end of the world? Are you busy? Will you save us?",
a="What are you doing while sending \"",
b="\"? Are you busy? Will you send \"",
c="\"?";
long long len[1<<17];
char f(int n,long long k)
{
	if(n==0)return s[k];
	if(k<a.length())
	{
		return a[k];
	}
	else if(k<a.length()+len[n-1])
	{
		return f(n-1,k-a.length());
	}
	else if(k<a.length()+len[n-1]+b.length())
	{
		return b[k-a.length()-len[n-1]];
	}
	else if(k<a.length()+b.length()+2*len[n-1])
	{
		return f(n-1,k-a.length()-len[n-1]-b.length());
	}
	else return c[k-a.length()-b.length()-2*len[n-1]];
}
main()
{
	len[0]=75;
	for(int i=1;i<56;i++)
	{
		len[i]=2*len[i-1]+68;
	}
	for(int i=56;i<=1e5;i++)len[i]=2e18;
	int q;cin>>q;
	for(int i=0;i<q;i++)
	{
		int n;long long k;cin>>n>>k;
		k--;
		if(k>=len[n])cout<<'.';
		else cout<<f(n,k);
	}
	cout<<endl;
}