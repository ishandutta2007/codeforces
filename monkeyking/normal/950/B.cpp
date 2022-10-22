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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
ll a[100005];
ll b[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	ll n,m;
	cin>>n>>m;
	rep(n)
	{
		scanf("%I64d",a+i);
	}
	rep(m)
	{
		scanf("%I64d",b+i);
	}
	ll x=a[0],y=b[0];
	ll i=1,j=1;
	ll ans=0;
	while(1)
	{
//		cout<<x<<' '<<y<<' '<<i<<' '<<j<<endl;
//		system("pause");
		if(x==y)
		{
			ans++;
			if(i==n && j==m) break;
			x=a[i++];
			y=b[j++];
			continue;
		}
		if(x<y)
		{
			x+=a[i++];
		}
		else if(x>y)
		{
			y+=b[j++];
		}
	}
	cout<<ans<<endl;
	return 0;
}