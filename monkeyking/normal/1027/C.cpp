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
int T;
int n;
int a[1000005];
pair<long double,pair<int,int> > b[1000005];
int k;
int real[100005];
map <int,int> m;
int realk;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>T;
	double t;
	while(T--)
	{
		realk=0;
		m.clear();
		k=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			if(m[a[i]])
			{
				real[realk++]=a[i];
				m[a[i]]=0;
			}
			else
			{
				m[a[i]]++;
			}
		}
		sort(real,real+realk);
		double minx=2e9;
		for(int i=0;i<realk-1;i++)
		{
//			if(a[i]==a[i+1] && a[i+2]==a[i+3])
//			{
				t=((double)real[i]/(real[i+1]))+((double)real[i+1]/real[i]);
//				cout<<t<<endl;
				if(t<minx)
				{
//			cout<<i<<endl;
					minx=t;
					k=i;
				}
//				b[k].first=(double)(a[i+2])/a[i]+(double)(a[i]/a[i+2]);
//				b[k].second.first=a[i];
//				b[k++].second.second=a[i+2];
//			}
		}
//		sort(b,b+k);
		printf("%d %d %d %d\n",real[k],real[k+1],real[k+1],real[k]);
	}
	return 0;
}