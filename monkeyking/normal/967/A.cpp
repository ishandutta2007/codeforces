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

int main()
{
//	freopen("input.txt","r",stdin);
	int n,s;
	cin>>n>>s;
	int a[105],x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a[i]=x*60+y;
	}
	if(1+s<=a[0])
	{
		cout<<0<<' '<<0<<endl;
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]+1+s+1+s<=a[i+1])
		{
			int k=a[i]+1+s;
			cout<<(k/60)<<' '<<(k%60)<<endl;
			return 0;
		}
	}
	int k=a[n-1]+1+s;
	cout<<(k/60)<<' '<<(k%60)<<endl;
	return 0;
}