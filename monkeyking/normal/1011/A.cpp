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

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	char c[55];
	scanf("%s",c);
	int a[55];
	for(int i=0;i<n;i++)
	{
		a[i]=c[i]-'a';
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	if(n<k) over(-1);
	int now=a[0];
	int step=1;
	int res=a[0]+1;
	for(int i=1;i<n;i++)
	{
//		cout<<(char)(now+'a');
		if(step==k)
		{
			cout<<res<<endl;
			return 0;
		}
		if(a[i]>=now+2)
		{
			res+=a[i]+1;
			now=a[i];
			step++;
		}
	}
	if(step==k)
	{
		cout<<res<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}