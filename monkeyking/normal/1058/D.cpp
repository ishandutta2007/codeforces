#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;

int main()
{	
//	freopen("input.txt","r",stdin);
	ll n,m,k;
	cin>>n>>m>>k;
	ll t=n*m;
	ll gcd=__gcd(t,k);
	if(k/gcd>2) over("NO\n");
	if(k==1) over("NO\n");
//	long double ln=n,lm=m,lk=k;
//	if(n*m*k<n*m/2)
	k/=gcd;
	if(k==1) t*=2;
	t/=gcd;
//	cout<<n<<' '<<m<<' '<<t<<endl;
//	cout<<t<<endl;
	ll a=__gcd(t,n);
	ll res1=a;
	ll res2=t/a;
	if(res2>m)
	{
		a=__gcd(t,m);
		res2=a;
		res1=t/a;
	}
	cout<<"YES\n";
	cout<<"0 0\n";
	cout<<"0 "<<res2<<endl;
	cout<<res1<<" 0"<<endl;
	return 0;
}