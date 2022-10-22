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
	int n,m,a,b,q;
	cin>>n>>m>>a>>b>>q;
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
			printf("%d\n",abs(y1-y2));
			continue;
		}
		ll res=0;
		res+=abs(x1-x2);
		if(y1<a)
		{
			res+=abs(y1-a)+abs(y2-a);
		}
		else if(y1>b)
		{
			res+=abs(y1-b)+abs(y2-b);
		}
		else
		{
			res+=abs(y1-y2);
		}
		printf("%d\n",res);
	}
	return 0;
}