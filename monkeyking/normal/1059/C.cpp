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
int n;
bool use[1000005];

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n;
	int basic=1;
	while(n)
	{
		if(n==3)
		{
			printf("%d %d %d\n",basic,basic,basic*3);
			return 0;
		}
		if(n==2)
		{
			printf("%d %d\n",basic,basic*2);
			return 0;
		}
		for(int i=1;i<=(n+1)/2;i++)
		{
			printf("%d ",basic);
		}
		basic*=2;
		n/=2;
	}
	return 0;
}