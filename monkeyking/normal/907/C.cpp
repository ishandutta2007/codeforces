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
set <int> can;
int flag;

int main()
{
//	freopen("input.txt","r",stdin);
	int ex[256];
	memset(ex,0,sizeof(ex));
	for(int i=(int)'a';i<=(int)'z';i++)
	{
		can.insert(i);
	}
	int n;
	cin>>n;
	char t;
	string c;
	int ans=0;
	bool know=false;
	int len=0;
	for(int i=0;i<n;i++)
	{
//		for(int i=(int)'a';i<=(int)'z';i++)
//		{
//			if(can.count(i)) cout<<(char)i<<' ';
//		}
//		cout<<endl;
		if(can.size()==1) know=true;
		cin>>t;
		cin>>c;
		if(know)
		{
			if(t=='!' || t=='?') ans++;
			continue;
		}
		if(t=='?')
		{
			can.erase((int)c[0]);
			continue;
		}
		if(t=='.')
		{
			len=c.size();
			for(int i=0;i<len;i++)
			{
				can.erase((int)c[i]);
			}
			continue;
		}
		len=c.size();
		flag++;
		for(int i=0;i<len;i++)
		{
			if(ex[c[i]]==flag-1) ex[c[i]]=flag;
		}
		for(int i=(int)'a';i<=(int)'z';i++)
		{
			if(ex[i]!=flag) can.erase(i);
		}
	}
	cout<<max(ans-1,0)<<endl;
	return 0;
}