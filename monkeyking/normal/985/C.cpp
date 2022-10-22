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
int n,k,l;
int a[100005];
ll res=0;
bool use[100005];

int main()
{
//	freopen("input.txt","r",stdin);
	int cpl=0;
	cin>>n>>k>>l;
	for(int i=0;i<n*k;i++)
	{
		scanf("%d",a+i);
	}
	sort(a,a+(n*k));
	int minx=a[0];
	int mx=a[0]+l;
	int can=upper_bound(a,a+(n*k),mx)-a-1;
	int remain=0;
	int now=can;
	for(int i=n*k-1;i>can;)
	{
		if(i-k+1<=can)
		{
			remain=k-(i-can);
			break;
		}
		if(now<0) over("0\n");
		res+=a[now];
		cpl++;
		now--;
		i-=k-1;
	}
//	cout<<cpl<<endl;
	if(cpl==n)
	{
		cout<<res<<endl;
		return 0;
	}
	if(now-remain+1<0) over("0\n");
	res+=a[now-remain+1];
	now-=remain;
	for(int i=now;i>=0;i-=k)
	{
		res+=a[i-k+1];
	}
	if(can<0) cout<<"0\n";else cout<<res<<endl;
	return 0;
}