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
const int mod=1e9+7;
ll e[200005];
char c[200005];
int n;

struct hash
{
	ll h[200005];
}a[26];

int gethash(int x,int l,int r)
{
	l--;
	return (((a[x].h[r]-(l>=0?a[x].h[l]*e[r-l]:0))%mod+mod)%mod);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,q;
	e[0]=1;
	for(int i=1;i<=200000;i++)
	{
		e[i]=e[i-1]*107;
		e[i]%=mod;
	}
	cin>>n>>q;
	scanf("%s",c);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i].h[j]=a[i].h[j-1]*107;
			if(c[j]==i+'a') a[i].h[j]++;
			a[i].h[j]%=mod;
		}
	}
//	for(int i=0;i<3;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<a[i].h[j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<gethash(0,0,1)<<' '<<gethash(1,0,1)<<endl;
//	cout<<gethash(0,4,5)<<' '<<gethash(1,4,5)<<endl;
//	return 0;
	while(q--)
	{
		int l1,l2,len;
		scanf("%d%d%d",&l1,&l2,&len);
		vector <int> v1,v2;
		for(int i=0;i<26;i++)
		{
			v1.push_back(gethash(i,l1-1,l1+len-2));
			v2.push_back(gethash(i,l2-1,l2+len-2));
//			break;
		}
		sort(all(v1));
		sort(all(v2));
//		for(int i=0;i<26;i++)
//		{
//			cout<<v1[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=0;i<26;i++)
//		{
//			cout<<v2[i]<<' ';
//		}
//		cout<<endl;
		if(v1==v2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}