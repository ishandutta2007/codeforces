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
	int a,b,c,d;
	cin>>a>>b>>c>>d; 
	for(int ca=0;ca<=200;ca++)
	{
		for(int cb=0;cb<=200;cb++)
		{
			for(int cc=0;cc<=200;cc++)
			{
				if(ca<=cb) continue;
				if(cb<=cc) continue;
				if(ca<a) continue;
				if(ca>a*2) continue;
				if(cb<b) continue;
				if(cb>b*2) continue;
				if(cc<c) continue;
				if(cc>c*2) continue;
				if(ca<d) continue;
				if(cb<d) continue;
				if(cc<d) continue;
				if(ca<=2*d) continue;
				if(cb<=2*d) continue;
				if(cc>2*d) continue;
				cout<<ca<<endl;
				cout<<cb<<endl;
				cout<<cc<<Endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}