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
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;

map <pii,int> times;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	string c;
	int s=0;
	int last=934850923;
	while(n--)
	{
		while(1)
		{
			cin>>c;
			if(c[0]=='[') break;
		}
		int hh=(c[1]-'0')*10+c[2]-'0';
		int mm=(c[4]-'0')*10+c[5]-'0';
		cin>>c;
		if(c[0]=='p') hh+=12;
		while(c[0]=='a' && hh>=12) hh-=12;
		while(c[0]=='p' && hh>=24) hh-=12;
		int now=hh*60+mm;
		times[mp(now,s)]++;
		if(times[mp(now,s)]>=10)
		{
			s++;
			last=now;
			continue;
		}
		if(now<last)
		{
			last=now;
			s++;
		}
		last=now;
//		cout<<now<<' '<<last<<Endl;
	}
	cout<<s<<endl;
	return 0;
}