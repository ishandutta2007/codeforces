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
vector <pii> vec;

int main()
{	
//	freopen("input.txt","r",stdin);
	int n,l,a;
	cin>>n>>l>>a;
	vec.push_back(mp(0,0));
	int x,y;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		vec.push_back(mp(x,y));
	}
	vec.push_back(mp(l,0));
	int res=0;
	for(int i=0;i<vec.size()-1;i++)
	{
		int k=vec[i+1].first-vec[i].first-vec[i].second;
		res+=k/a;
	}
	cout<<res<<endl;
	return 0;
}