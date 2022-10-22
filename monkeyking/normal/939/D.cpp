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
int f[256];
string a,b;

int find(int x)
{
	return (f[x]==x?x:f[x]=find(f[x]));
}

void init()
{
	rep(256)
	{
		f[i]=i;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int temp;
	cin>>temp;
	init();
	cin>>a>>b;
	int len=a.size();
	vector <pair<char,char> >vec;
	rep(len)
	{
		if(find(a[i])==find(b[i])) continue;
		if(rand()&1) f[find(a[i])]=find(b[i]);else f[find(b[i])]=find(a[i]);
		vec.push_back(mp(a[i],b[i]));
	}
	cout<<vec.size()<<endl;
	rep(vec.size())
	{
		cout<<vec[i].first<<' '<<vec[i].second<<endl;
	}
	return 0;
}