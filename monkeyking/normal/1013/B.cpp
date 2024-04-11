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
int n,x;
int a[100005];
int have[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		have[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(have[a[i]]>1) over("0");
	}
	memset(have,0,sizeof(have));
	for(int i=0;i<n;i++)
	{
		have[(a[i]&x)]++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==(a[i]&x))
		{
//			cout<<"F";
			if(have[a[i]]>1) over("1");
		}
		else if(have[a[i]]==1) over("1");
	}
	memset(have,0,sizeof(have));
	for(int i=0;i<n;i++)
	{
		a[i]=(a[i] & x);
		have[a[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(have[a[i]]>1) over("2");
	}
	cout<<-1<<endl;
	return 0;
}