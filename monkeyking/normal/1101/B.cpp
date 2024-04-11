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
char c[500005];
int n;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	n=strlen(c);
	int l=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='[')
		{
			l=i;
			break;
		}
	}
	if(l==-1) over("-1");
	int r=n;
	for(int i=n-1;i>=0;i--)
	{
		if(c[i]==']')
		{
			r=i;
			break;
		}
	}
	if(r==n)
	{
		cout<<-1<<endl;
		return 0;
	}
	int fll=l,frr=r;
	for(int i=l+1;i<r;i++)
	{
		if(c[i]==':')
		{
			fll=i;
			break;
		}
	}
	for(int i=r-1;i>l;i--)
	{
		if(c[i]==':')
		{
			frr=i;
			break;
		}
	}
	if(fll==l || frr==r || fll==frr) over("-1");
	int res=0;
	for(int i=fll;i<=frr;i++)
	{
		if(c[i]=='|') res++;
	}
	cout<<res+4<<endl;
	return 0;
}