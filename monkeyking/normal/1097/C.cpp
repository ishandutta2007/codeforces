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
int n;
char c[500005];
vector <int> vec;

int calc()
{
	int s=0;
	int len=strlen(c)-1;
	bool l=true,r=true;
	for(int i=0;i<strlen(c);i++)
	{
		if(c[i]=='(') s++;else s--;
		if(s<0) l=false;
	}
	s=0;
	for(int i=strlen(c)-1;i>=0;i--)
	{
		if(c[i]=='(') s--;else s++;
		if(s<0) r=false;
	}
	if(l==false && r==false) return inf;
	return s;
//	if(l) return s;else return -s;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c);
		int x=calc();
		if(x!=inf) vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
//	for (auto i:vec)
//	{
//		cout<<i<<endl;
//	}
	int res=0;
	int r=vec.size()-1;
	for(int i=0;i<r;i++)
	{
		while((vec[r]+vec[i])>0 && r>i && abs(vec[r])>abs(vec[i])) r--;
		while((vec[r]+vec[i])>0 && r>i && abs(vec[i])>abs(vec[r])) i++;
		if(i==r) break;
		if(vec[r]+vec[i]==0)
		{
			res++;
			r--;
		}
	}
	cout<<res<<endl;
	return 0;
}