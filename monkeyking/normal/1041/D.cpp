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
int n,h;
int l[200005];
int r[200005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",l+i,r+i);
	}
//	cout<<endl;
	ll x=0,y=0,ati=h,res=-1,len=r[0]-l[0];
	res=max(res,len+ati);
	while(y<n-1)
	{
		if(l[y+1]-r[y]>=ati)
		{
			res=max(res,len+ati);
			break;
		}
		else
		{
			ati-=(l[y+1]-r[y]);
			len+=r[y+1]-r[y];
//			cout<<l[y+1]<<' '<<r[y]<<'f'<<y<<endl;
			y++;
//			cout<<len<<' '<<y<<endl;
			res=max(res,len+ati);
		}
//		cout<<ati<<"-\n";
	}
//	cout<<len<<'-'<<0<<'-'<<ati<<endl;
	for(int i=1;i<n;i++)
	{
		len-=l[i]-l[x];
//		cout<<len<<endl;
		ati+=l[i]-r[x++];
		while(y<n-1)
		{
//			cout<<"FICL";
			if(l[y+1]-r[y]>=ati)
			{
				res=max(res,len+ati);
				break;
			}
			else
			{
				ati-=(l[y+1]-r[y]);
				len+=r[y+1]-r[y];
//				cout<<r[y+1]<<' '<<r[y]<<'-'<<y<<endl;
				y++;
				res=max(res,len+ati);
			}
		}
//		cout<<len<<' '<<i<<' '<<y<<endl;
	}
	cout<<res<<endl;
	return 0;
}