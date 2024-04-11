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

struct form
{
	int score;
	int id;
}a[1005];

bool compare(form a,form b)
{
	if(a.score!=b.score) return a.score>b.score;
	return a.id<b.id;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int b,c,d,e;
	for(int i=0;i<n;i++)
	{
		cin>>b>>c>>d>>e;
		a[i].score=b+c+d+e;
		a[i].id=i;
	}
	sort(a,a+n,compare);
	for(int i=0;i<n;i++)
	{
		if(a[i].id==0)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}