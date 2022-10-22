#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
int arr[MaxN],Pre[MaxN],Suf[MaxN];
bool equ[MaxN],eps[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) cin>>arr[i];
		int Cnt=0;
		rep(i,1,n-1) equ[i]=(arr[i]==arr[i+1]),Cnt+=equ[i];
		if(Cnt<=1)
			{cout<<"0\n";continue;}
		if(n==3)
			{cout<<"1\n";continue;}
		rep(i,1,n-1) eps[i]=equ[i];
		rep(i,1,n-3)
		{
			Pre[i]=Pre[i-1];
			if(eps[i])
			{
				++Pre[i];
				eps[i]=false;
				eps[i+1]=true;
				eps[i+2]=false;
			}
		}
		rep(i,1,n-1) eps[i]=equ[i];
		Suf[n]=Suf[n+1]=Suf[n+2]=0;
		dow(i,n,4)
		{
			Suf[i]=Suf[i+1];
			if(eps[i])
			{
				++Suf[i];
				eps[i]=false;
				eps[i-1]=true;
				eps[i-2]=false;
			}
		}
		int Ans=(n<<3);
		rep(i,2,n-1)
			Ans=min(Ans,Pre[i-2]+Suf[i+2]+1);
		cout<<Ans<<'\n';
	}
	return 0;
}