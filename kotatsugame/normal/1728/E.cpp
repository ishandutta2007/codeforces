#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
T extgcd(T a,T b,T&x,T&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	T q=a/b;
	T g=extgcd(b,a-q*b,y,x);
	y-=q*x;
	return g;
}
int N,M;
int B[3<<17];
long long SB[3<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	long long SA=0;
	for(int i=0;i<N;i++)
	{
		int A,b;cin>>A>>b;
		SA+=A;
		B[i]=b-A;
	}
	sort(B,B+N);
	int mxi=0;
	for(int i=0;i<N;i++)
	{
		SB[i+1]=SB[i]+B[N-i-1];
		if(SB[mxi]<SB[i+1])mxi=i+1;
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		long long X,Y;cin>>X>>Y;
		long long k,l;
		long long g=extgcd(X,Y,k,l);
		if(N%g!=0)
		{
			cout<<"-1\n";
			continue;
		}
		k*=N/g;l*=N/g;
		long long x=X/g,y=Y/g;
		if(k<0)
		{
			long long t=(-k+y-1)/y;
			k+=y*t;
			l-=x*t;
		}
		if(l<0)
		{
			long long t=(-l+x-1)/x;
			k-=y*t;
			l+=x*t;
		}
		if(k<0)
		{
			cout<<"-1\n";
			continue;
		}
		long long f=l*Y,d=x*Y;
		long long ans=-1;
		if(f>=mxi)
		{
			f-=(f-mxi)/d*d;
			if(f<=N)ans=max(ans,SA+SB[f]);
			if(f>=d&&f-d<=N)ans=max(ans,SA+SB[f-d]);
		}
		else
		{
			f+=(mxi-f)/d*d;
			if(f<=N)ans=max(ans,SA+SB[f]);
			if(f+d<=N)ans=max(ans,SA+SB[f+d]);
		}
		cout<<ans<<"\n";
	}
}