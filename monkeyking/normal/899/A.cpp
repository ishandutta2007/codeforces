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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int a[n];
	int s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1) s1++;else s2++;
	}
	int s=0;
	if(s1>s2)
	{
		s+=s2;
		s1-=s2;
		s+=s1/3;
	}
	else
	{
		s=s1;
	}
	cout<<s<<endl;
	return 0;
}