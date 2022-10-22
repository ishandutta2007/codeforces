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
int n,k;
int f[105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	int x;
	for(int i=0;i<k;i++)
	{
		printf("%d\n",1);
		fflush(stdout);
		scanf("%d",&x);
		if(x==0) exit(0);
		if(x==-2) exit(0);
		if(x==1)
		{
			f[i]=1;
		}
		else
		{
			f[i]=-1;
		}
	}
//	over(0);
	//shit code, my bs got wrong.
	int left = 2,ri =n;
	int i=0;
	while (left <= ri)
	{
	    int mid = (left + ri)/2;
	    printf("%d\n",mid);
	    fflush(stdout);
		scanf("%d",&x);
		if(x==0) exit(0);
		if(x==-2) exit(0);
		x*=f[i++];
		i%=k;
	    if(x==1) left = mid+1;
	    else ri= mid-1;
	}
	return 0;
}