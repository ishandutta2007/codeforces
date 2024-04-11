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
int n,m;
char a[1005];
char b[1005];
int sum[1005];
bool can[1005];

bool cover(int x)
{
	for(int i=0;i<m;i++)
	{
		if(a[i+x]!=b[i]) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int q;
	cin>>q;
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<n-m+1;i++)
	{
		can[i]=cover(i);
	}
	sum[0]=can[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+can[i];
	}
//	cout<<can[13]<<endl;
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r--;
		l--;
		l--;
		printf("%d\n",max(0,(r-m+1<0?0:sum[r-m+1])-sum[l]));
	}
	return 0;
}