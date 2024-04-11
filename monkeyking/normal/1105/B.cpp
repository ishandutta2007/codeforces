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
char c[200005];
int n,k;
int s[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	scanf("%s",c);
	int res=0;
	int now=0;
	for(int i='a';i<='z';i++)
	{
		now=0;
		memset(s,0,sizeof(s));
		s[n-1]=(c[n-1]==i);
		for(int j=n-2;j>=0;j--)
		{
			s[j]=s[j+1]+(c[j]==i);
			if(c[j]!=i) s[j]=0;
		}
		for(int j=0;j<n;)
		{
//			cout<<i<<' '<<4j<<endl;
			if(s[j]>=k)
			{
				now++;
				j+=k;
			}
			else
			{
				j++;
			}
		}
		res=max(res,now);
	}
	cout<<res<<endl;
	return 0;
}