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
typedef unsigned long long ull;
using namespace std;
const ll llinf=1e12;
string c;
int len;
int cl[50005],cr[50005];
int w;
set <pair<ll,int> > squ;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>c;
	len=c.size();
	ll x,y;
	ll res=0;
	int s=0;
	for(int i=0;i<len;i++)
	{
		if(c[i]=='(')
		{
			x=0;
			y=llinf;
		}
		else if(c[i]==')')
		{
			x=llinf;
			y=0;
		}
		else
		{
			cin>>x>>y;
		}
		res+=y;
		s--;
		squ.insert(mp(x-y,i));
		c[i]=')';
		if(s<0)
		{
			res+=squ.begin()->first;
			c[squ.begin()->second]='(';
			squ.erase(squ.begin());
			s+=2;
		}
	}
	if(res>=llinf)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<res<<endl;
	cout<<c<<endl;
	return 0;
}