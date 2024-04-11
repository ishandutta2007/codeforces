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
	int a,d;
	cin>>a>>d;
	string c;
	cin>>c;
	int len=c.size();
	bool b[len];
	for(int i=0;i<len;i++)
	{
		if(c[i]=='0') b[i]=false;else b[i]=true;
	}
	int now=0,ans=0;
	for(int i=0;i<len;i++)
	{
		i=now;
		for(int j=i+d;j>=i;j--)
		{
			if(j>=len) continue;
			if(j==len-1)
			{
				cout<<ans+1<<endl;
				return 0;
			}
			if(j==i)
			{
				cout<<-1<<endl;
				return 0;
			}
			if(!b[j]) continue;
			now=j;
// 			cout<<now<<endl;
			ans++;
			break;
		}
	}
	return 0;
}