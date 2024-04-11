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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
string c;

void solve(int l,int r,char e,char d)
{
	for(int i=l;i<r;i++)
	{
		if(c[i]==e) c[i]=d;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	cin>>c;
	while(m--)
	{
		int a,b;
		char c,d;
		cin>>a>>b>>c>>d;
		a--;
//		cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
		solve(a,b,c,d);
	}
	cout<<c<<endl;
	return 0;
}