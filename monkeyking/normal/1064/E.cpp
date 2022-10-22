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
srand(1828);
	int n;
	cin>>n;
	int l,r;
	l=0,r=1e9;
	cout<<0<<' '<<0<<endl;
	fflush(stdout);
	string x,left;
	cin>>left;
	for(int i=0;i<n-1;i++)
	{
		bool fuck=rand()&1;
		cout<<(l+r+fuck)/2<<' '<<1<<endl;
		fflush(stdout);
		cin>>x;
		if(left==x)
		{
			l=(l+r+fuck)/2;
		}
		else
		{
			r=(l+r+fuck)/2;
		}
	}
	cout<<(l+r)/2<<' '<<0<<' '<<(l+r+1)/2<<' '<<1000000000<<endl;
	fflush(stdout);
	return 0;
}