#include<iostream>
using namespace std;
int N,Q,mod;
int fib[3<<17];
int A[3<<17],C[3<<17],zc;
void add(int id,int val)
{
	if(C[id]==0)zc--;
	C[id]+=val;
	if(C[id]>=mod)C[id]-=mod;
	if(C[id]==0)zc++;
}
int neg(int val)
{
	return val==0?0:mod-val;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q>>mod;
	fib[0]=0;fib[1]=1%mod;
	for(int i=2;i<3<<17;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		if(fib[i]>=mod)fib[i]-=mod;
	}
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		A[i]=a;
	}
	for(int i=0;i<N;i++)
	{
		int b;cin>>b;
		A[i]-=b;
		if(A[i]<0)A[i]+=mod;
	}
	for(int i=0;i<N;i++)
	{
		C[i]=A[i];
		if(i>0)
		{
			C[i]-=A[i-1];
			if(C[i]<0)C[i]+=mod;
		}
		if(i>1)
		{
			C[i]-=A[i-2];
			if(C[i]<0)C[i]+=mod;
		}
		if(C[i]==0)zc++;
	}
	for(;Q--;)
	{
		char op;int l,r;cin>>op>>l>>r;
		l--;
		int len=r-l;
		if(op=='A')
		{
			add(l,1);
			if(r<N)add(r,neg(fib[len+1]));
			if(r+1<N)add(r+1,neg(fib[len]));
		}
		else
		{
			add(l,neg(1));
			if(r<N)add(r,fib[len+1]);
			if(r+1<N)add(r+1,fib[len]);
		}
		cout<<(zc==N?"YES\n":"NO\n");
	}
}