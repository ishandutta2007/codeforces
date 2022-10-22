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
char c[105];
int a[105];
int n;
int k;

bool check(int x)
{
	int now=0;
	for(int i=0;i<k;i++)
	{
//		if(x==1) cout<<now<<' '<<i<<endl;
		now+=a[i];
		if(now==x)
		{
			now=0;
		}
		else if(now>x)
		{
			return false;
		}
	}
	if(now!=0) return false;
	return true;
}

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",c);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		a[k++]=c[i]-'0';
		sum+=c[i]-'0';
//		cout<<k<<endl;
		if(a[k-1]==0) k--;
	}
	if(k==0) over("YES\n");
//	cout<<k<<endl;
//cout<<sum<<endl;
	for(int i=1;i<sum;i++)
	{
//		cout<<i<<endl;
		if(check(i)) over("YES\n");
	}
	cout<<"NO\n";
	return 0;
}