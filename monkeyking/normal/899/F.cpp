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
const int V=300;
using namespace std;
int n;
int b[200000/V+1][V+5];
int len[200000/V+1];
bool isdel[200000/V+1][128];
char c[200005];
int sum[200000/V+1][128];

void delall(int x,char c)
{
	if(isdel[x][c]) return;
	isdel[x][c]=true;
	len[x]-=sum[x][c];
}

void del(int x,int l,int r,char c,int now)
{
//	cout<<x<<' '<<l<<' '<<r<<' '<<c<<' '<<now<<endl;
	int count=0;
	int k=0;
	for(int i=0;b[x][i];i++)
	{
		if(isdel[x][b[x][i]]) continue;
		if(now+count>=l && now+count<r && b[x][i]==c)
		{
			sum[x][b[x][i]]--;
			count++;
			continue;
		}
		count++;
		b[x][k++]=b[x][i];
	}
	len[x]=k;
	b[x][k]=0;
}

void solve(int l,int r,char c)
{
	int len=ceil(n,V);
	int now=0;
	for(int i=0;i<len;i++)
	{
//		cout<<now<<endl;
		if(now>=l && now+::len[i]<=r)
		{
			now+=::len[i];
			delall(i,c);
		}
		else if(now>=r) break;
		else if(now+::len[i]<=l) now+=::len[i];
		else
		{
			int temp=::len[i];
			del(i,l,r,c,now);
			now+=temp;
		}
	}
}

void print()
{
//	for(int i=0;i<ceil(n,V);i++)
//	{
//		cout<<len[i]<<' ';
//	}
//	cout<<endl;
	for(int i=0;i<ceil(n,V);i++)
	{
		for(int j=0;b[i][j];j++)
		{
			if(!isdel[i][b[i][j]]) printf("%c",b[i][j]);
		}
	}
	cout<<endl;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int q;
	scanf("%d%d",&n,&q);
	scanf("%s",c);
	for(int i=0;i<ceil(n,V);i++)
	{
		for(int j=0;i*V+j<n && j<V;j++)
		{
			len[i]++;
			sum[i][c[i*V+j]]++;
			b[i][j]=c[i*V+j];
		}
	}
	int l,r;
	char x;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		getchar();
		x=getchar();
		l--;
		solve(l,r,x);
	}
	print();
	return 0;
}