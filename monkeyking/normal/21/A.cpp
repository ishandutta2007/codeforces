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
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
string c;

void wrong()
{
	cout<<"NO\n";
	exit(0);
}

void gg(int l,int r,char cc,int t)
{
	int s=0;
	for(int i=l;i<r;i++)
	{
		if(c[i]==cc) s++;
	}
	if(s>t) wrong();
}

void f1(int l,int r)
{
	if((r-l)<1 || (r-l)>16) wrong();
	for(int i=l;i<r;i++)
	{
		if(c[i]=='_') continue;
		if(isdigit(c[i])) continue;
		if(isalpha(c[i])) continue;
		wrong();
	}
}

void f2(int l,int r)
{
	if((r-l)<1 || (r-l)>32) wrong();
	for(int i=l;i<r;i++)
	{
		if(c[i]=='_') continue;
		if(isdigit(c[i])) continue;
		if(isalpha(c[i])) continue;
		if(c[i]=='.') continue;
		wrong();
	}
	int i=l;
	string t=c.substr(l,r-l);
	t+='.';
	int len=0;
	for(i=0;i<t.size();i++)
	{
		if(t[i]=='.')
		{
			if(len>16 || len<1) wrong();
//			cout<<len<<endl;
			len=0;
		}
		else len++;
	}
}

void f3(int l,int r)
{
	if(r-l<1) wrong();
	if(r-l>16) wrong();
	for(int i=l;i<r;i++)
	{
		if(c[i]=='_') continue;
		if(isalpha(c[i])) continue;
		if(isdigit(c[i])) continue;
		wrong();
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>c;
	gg(0,c.size(),'/',1);
	gg(0,c.size(),'@',1);
	int i;
	for(i=0;i<c.size();i++)
	{
		if(c[i]=='@')
		{
			f1(0,i);
			break;
		}
	}
	int st=++i;
	for(;i<=c.size();i++)
	{
		if(i==c.size() || c[i]=='/')
		{
			f2(st,i);
			break;
		}
	}
	if(i!=c.size())
	{
		f3(i+1,c.size());
	}
	cout<<"YES\n";
	return 0;
}