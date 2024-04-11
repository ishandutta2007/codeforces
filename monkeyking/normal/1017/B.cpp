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
int n;
char a[100005];
char b[100005];
int sum[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",a);
	scanf("%s",b);
	ll s=0;
	for(int i=0;i<n;i++)
	{
		a[i]-='0';
		b[i]-='0';
		s+=a[i];
	}
	ll res=s*(n-s);
//	for(int i=1;i<n;i++)
//	{
//		res+=a[i]*sum[i-1];
//	}
	res=s*(n-s);
	ll s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]==0) continue;
		s1+=(a[i]==0);
		s2+=(a[i]==1);
	}
	cout<<res-s2*s1<<endl;
	return 0;
}