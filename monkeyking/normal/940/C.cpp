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
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
char c[100005];
int n,k;
bool can[256];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
	char m=48,x='z'+1;
	for(int i=0;i<n;i++)
	{
		can[c[i]]=true;
		m=max(m,c[i]);
		x=min(x,c[i]);
	}
// 	cout<<x<<endl;
	int w=-1;
	for(int i=k-1;i>=0;i--)
	{
		if(k>n) continue;
		if(m>c[i])
		{
			w=i;
			break;
		}
	}
	if(w==-1)
	{
		for(int i=0;i<k;i++)
		{
			if(i<n) cout<<c[i];else cout<<x;
		}
		cout<<endl;
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		if(i==w)
		{
			char t=m;
			for(int j='a';j<='z';j++)
			{
				if(can[j] && j>c[i])
				{
					t=j;
					break;
				}
			}
			cout<<t;
			for(int j=i+1;j<k;j++)
			{
				cout<<x;
			}
			cout<<endl;
			return 0;
		}
		cout<<c[i];
	}
	return 0;
}