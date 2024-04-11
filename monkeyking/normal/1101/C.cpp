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
int T;
int n;
pair<pair<int,int>,int> a[100005];
int minx[100005];
vector <int> res;
bool use[100005];

void solve()
{
	res.clear();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		use[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].first.first,&a[i].first.second);
		a[i].second=i;
	}
	sort(a,a+n);
	minx[n]=200005;
	for(int i=n-1;i>=0;i--)
	{
		minx[i]=min(minx[i+1],a[i].first.second);
	}
	int r=a[0].first.second;
	bool flag=false;
	res.push_back(a[0].second);
	for(int i=1;i<n;i++)
	{
//		cout<<a[i].first.first<<endl;
		if(r<a[i].first.first)
		{
			flag=true;
			break;
		}
		r=max(r,a[i].first.second);
		res.push_back(a[i].second);
	}
	if(flag==false)
	{
		printf("-1\n");
	}
	else
	{
		for(int i=0;i<res.size();i++)
		{
			use[res[i]]=true;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d ",(int)use[i]+1);
		}
		printf("\n");
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}