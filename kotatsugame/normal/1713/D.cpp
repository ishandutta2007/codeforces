#include<iostream>
using namespace std;
int ask(int a,int b)
{
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	int r;cin>>r;
	return r;
}
int f(int L,int R)
{
	if(L+1==R)return L;
	int W=R-L;
	int a=f(L,L+W/4);
	int b=f(L+W/4,L+W/4*2);
	int c=f(L+W/4*2,L+W/4*3);
	int d=f(L+W/4*3,L+W/4*4);
	int t=ask(a,c);
	if(t==1)
	{//a>c
		int u=ask(a,d);
		if(u==1)return a;
		else return d;
	}
	else if(t==2)
	{//a<c
		int u=ask(b,c);
		if(u==1)return b;
		else return c;
	}
	else
	{//a==c
		int u=ask(b,d);
		if(u==1)return b;
		else return d;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		if(N%2==1)
		{
			int a=f(0,1<<N-1);
			int b=f(1<<N-1,1<<N);
			int x=ask(a,b);
			if(x==1)cout<<"! "<<a+1<<endl;
			else cout<<"! "<<b+1<<endl;
		}
		else
		{
			int a=f(0,1<<N);
			cout<<"! "<<a+1<<endl;
		}
	}
}