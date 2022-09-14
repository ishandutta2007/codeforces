#include<iostream>
using namespace std;
int N,a,b;
bool isp[400001];
main()
{
	cin>>N;
	isp[0]=isp[1]=1;
	for(int i=2;i*i<=400000;i++)
	{
		if(isp[i])continue;
		for(int j=i+i;j<=400000;j+=i)isp[j]=1;
	}
	for(int i=0;i<N;i++)
	{
		int c;cin>>c;
		if(c==1)a++;
		else b++;
	}
	int now=0;
	for(int i=0;i<N;i++)
	{
		if(a==0||b==0)
		{
			if(a==0)
			{
				cout<<2;
				now+=2;
				b--;
			}
			else
			{
				cout<<1;
				now+=1;
				a--;
			}
		}
		else if(!isp[now+1])
		{
			cout<<1;
			now++;
			a--;
		}
		else if(!isp[now+2])
		{
			cout<<2;
			now+=2;
			b--;
		}
		else if(now%2==1&&a==1)
		{
			cout<<2;
			now+=2;
			b--;
		}
		else
		{
			cout<<1;
			now+=1;
			a--;
		}
		cout<<(i==N-1?"\n":" ");
	}
}