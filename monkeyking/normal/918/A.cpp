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
typedef unsigned long long ull;
using namespace std;
int a[3005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	a[0]=1;
	a[1]=1;
	for(int i=2;i<1003;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	bool c[3005];
	memset(c,false,sizeof(c));
	for(int i=0;a[i]<=3000;i++)
	{
		c[a[i]]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]) cout<<'O';else cout<<'o';
	}
	cout<<endl;
	return 0;
}