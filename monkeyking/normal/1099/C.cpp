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
char c[205];
int len;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	len=strlen(c);
	int s1=0,s2=0;
	for(int i=0;i<len;i++)
	{
		if(c[i]=='?')
		{
			s1++;
		}
		else if(c[i]=='*')
		{
			s2++;
		}
	}
	int k;
	cin>>k;
	int lb=len-s1-s2-s1-s2;
	if(lb>k)
	{
		cout<<"Impossible\n";
		return 0;
	}
	if(s2)
	{
		int curlen=len-s1-s2;
		string res="";
		for(int i=0;i<len;i++)
		{
			if(isalpha(c[i]))
			{
				res.push_back(c[i]);
			}
			else
			{
				if(curlen>k)
				{
					curlen--;
					res.pop_back();
				}
				else if(c[i]=='*')
				{
					while(curlen<k)
					{
						res.push_back(c[i-1]);
						curlen++;
					}
				}
			}
		}
		cout<<res<<endl;
		return 0;
	}
	int ub=len-s1;
	if(ub<k)
	{
		cout<<"Impossible\n";
		return 0;
	}
	int curlen=len-s1;
	string res="";
	for(int i=0;i<len;i++)
	{
		if(isalpha(c[i]))
		{
			res.push_back(c[i]);
		}
		else
		{
			if(curlen>k)
			{
				curlen--;
				res.pop_back();
			}
		}
	}
	cout<<res<<endl;
	return 0;
}