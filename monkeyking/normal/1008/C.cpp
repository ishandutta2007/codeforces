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
int a[100005];
int b[100005];
//int c[100005];
//pair<int,int> b[2*100005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		b[i]=a[i];
//		b[i]=mp(a[i],i);
	}
	queue <int> que;
//	sort(b,b+n);
	sort(b,b+n);
//	sort(c,c+n);
//	reverse(c,c+n);
//	que.push(c[0]);
//	int now=c[0];
	int i=0,j=n-1;
	int res=0;
	for(int i=0;i<n;i++)
	{
//		cout<<que.size()<<endl;
//		cout<<now<<endl;
		que.push(b[j]);
//		if(i>=j) break;
//		cout<<que.front()<<endl;
		j--;
//		now=a[j--];
		for(;j>=0;j--)
		{
			if(que.front()!=b[j])
			{
				que.pop();
				que.push(b[j]);
//				now=b[j];
				res++;
				continue;
			}
			break;
		}
//		if(i>=j) break;
//		if(t[i]=t[i-1])
//		{
//			que.push(a[j--]);
//			continue;
//		}
	}
	cout<<res<<endl;
	return 0;
}