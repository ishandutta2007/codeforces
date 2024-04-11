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
char c[100005];
vector <int> vec;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	scanf("%s",c);
	int now=0;
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='S')
		{
			if(now) s++;
			vec.push_back(now);
			now=0;
		}
		else
		{
			now++;
		}
	}
	if(now) s++;
	vec.push_back(now);
	now=0;
//	cout<<s<<endl;
	if(s==0)
	{
		cout<<0<<endl;
	}
	else if(vec.size()==1)
	{
//		cout<<s<<endl;
		cout<<vec[0]<<endl;
	}
	else if(s==1)
	{
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i])
			{
				cout<<vec[i]<<endl;
				break;
			}
		}
	}
	else if (s==2)
	{
		int res=0;
		for(int i=0;i<vec.size();i++)
		{
			if(vec[i]) res=max(res,vec[i]+1);
		}
		for(int i=0;i<vec.size()-1;i++)
		{
			if(vec[i])
			{
				if(vec[i+1])
				{
					res=max(res,vec[i]+vec[i+1]);
				}
			}
		}
		cout<<res<<endl;
	}
	else
	{
		int res=0;
		for(int i=0;i<vec.size()-1;i++)
		{
			if(vec[i]+vec[i+1]+1>res)
			{
				res=vec[i]+vec[i+1]+1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}