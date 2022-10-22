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
int x[100005];
int d[100005];
long long res;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",x+i,d+i);
		res+=x[i]*n;
	}
	for(int i=0;i<m;i++)
	{
		if(d[i]>0)
		{
			res+=1LL*d[i]*(n-1)*n/2;
		}
		else if(n&1)
		{
			res+=(1LL*d[i]*n*n-d[i])/4;
		}
		else
		{
			res+=1LL*d[i]*n*n/4;
		}
//		cout<<res<<endl;
	}
	double x=(long double)res/n;
	cout.precision(10);
	cout<<x<<endl;
	return 0;
}