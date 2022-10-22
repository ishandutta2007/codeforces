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
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;

void solve()
{
	int n,x,y,d;
	cin>>n>>x>>y>>d;
	int t=abs(x-y);
	if(t%d==0)
	{
		cout<<t/d<<endl;
		return;
	}
	else if((y-1)%d==0 && (n-y)%d==0)
	{
		cout<<min((y-1)/d+ceil(x-1,d),(n-y)/d+ceil(n-x,d))<<endl;
		return;
	}
	else if((y-1)%d==0)
	{
		cout<<(y-1)/d+ceil(x-1,d)<<endl;
	}
	else if((n-y)%d==0)
	{
		cout<<(n-y)/d+ceil(n-x,d)<<endl;
	}
	else 
	{
		cout<<-1<<endl;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}