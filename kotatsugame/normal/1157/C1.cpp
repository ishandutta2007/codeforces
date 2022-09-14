#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,a[2<<17];
string ans="";
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",a+i);
	int L=0,R=N-1;
	int now=0;
	while(L<=R)
	{
		if(a[L]<a[R])
		{
			if(a[L]>now)
			{
				ans+='L';
				now=a[L++];
			}
			else if(a[R]>now)
			{
				ans+='R';
				now=a[R--];
			}
			else
			{
				break;
			}
		}
		else if(a[R]<a[L])
		{
			if(a[R]>now)
			{
				ans+='R';
				now=a[R--];
			}
			else if(a[L]>now)
			{
				ans+='L';
				now=a[L++];
			}
			else
			{
				break;
			}
		}
		else
		{
			if(a[L]<=now)break;
			string X="L",Y="R";
			for(int i=L+1;i<=R;i++)
			{
				if(a[i-1]<a[i])X+='L';
				else break;
			}
			for(int i=R-1;i>=L;i--)
			{
				if(a[i+1]<a[i])Y+='R';
				else break;
			}
			if(X.size()<Y.size())ans+=Y;
			else ans+=X;
			break;
		}
	}
	cout<<ans.size()<<endl<<ans<<endl;
}