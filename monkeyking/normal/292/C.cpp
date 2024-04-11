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
vector <int> vec_t;
vector <string> ans;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,t,need=0;
	bool a[10];
	memset(a,false,sizeof(a)); 
	cin>>n;
	if(n>6)
	{
		cout<<0<<Endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>t;
		a[t]=true;
		need|=(1<<t);
	}
	int len[256],num[256][5],mask[256];
	bool good[256];
	memset(len,0,sizeof(len));
	memset(good,true,sizeof(good));
	memset(mask,0,sizeof(mask)); 
	for(int i=0;i<256;i++)
	{
		t=i;
		while(t)
		{
			num[i][len[i]++]=t%10;
			if(!a[t%10]) good[i]=false;
			mask[i]|=(1<<(t%10));
			t/=10;
		}
		if(i==0 && !a[0]) good[0]=false,mask[0]=1<<0;
		if(i==0)
		{
			num[0][len[0]++]=0;
			mask[0]|=(1<<0);
		}
	}
//	for(int i=0;i<256;i++)
//	{
//		for(int j=len[i]-1;j>=0;j--)
//		{
//			cout<<num[i][j];
//		}
//		cout<<endl;
//	}
	vector <pair<pii,pii> > ans;
	for(int i=0;i<256;i++)
	{
		if(!good[i]) continue;
		for(int j=0;j<256;j++)
		{
			if(!good[j]) continue;
			for(int k=0;k<256;k++)
			{
				if(!good[k]) continue;
				if((mask[i] | mask[j] | mask[k])!=need) continue;
				for(int d=0;d<256;d++)
				{
					if(!good[d]) continue;
					vec_t.clear();
					for(int o=len[i]-1;o>=0;o--) vec_t.push_back(num[i][o]);
					for(int o=len[j]-1;o>=0;o--) vec_t.push_back(num[j][o]);
					for(int o=len[k]-1;o>=0;o--) vec_t.push_back(num[k][o]);
					for(int o=len[d]-1;o>=0;o--) vec_t.push_back(num[d][o]);
					int anslen=vec_t.size();
//					cout<<anslen<<endl;
					for(int o=0;o<anslen;o++)
					{
//						cout<<vec_t[o];
//						cout<<o<<' '<<anslen-o-1<<endl;
						if(vec_t[o]!=vec_t[anslen-o-1]) goto end;
//						cout<<vec_t[o]<<' '<<vec_t[anslen-o-1]<<endl;
					}
//					cout<<endl;
					ans.push_back(mp(mp(i,j),mp(k,d)));
//					printf(string_t,"%d.%d.%d.%d\n",i,j,k,d);
//					system("pause");
					end:;
				}
			}
		}
	}
	cout<<ans.size()<<endl;
	rep(ans.size())
	{
		int a,b,c,d;
		a=ans[i].first.first;
		b=ans[i].first.second;
		c=ans[i].second.first;
		d=ans[i].second.second;
		printf("%d.%d.%d.%d\n",a,b,c,d);
	}
	return 0;
}