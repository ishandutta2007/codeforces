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
char c[100005];
int s[256];

int main()
{	
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	scanf("%s",c);
	sort(c,c+n);
	printf("%s",c);
//	for(int i=0;i<n;i++)
//	{
//		s[c[i]]++;
//	}
//	char t=' ';
//	for(int i='a';i<='z';i++)
//	{
//		if(s[i]&1 && t==' ')
//		{
//			t=i;
//		}
//		else if(s[i]&1)
//		{
//			printf("%c",i);
//		}
//	}
//	for(int i='a';i<='z';i++)
//	{
//		for(int j=0;j<s[i]/2;j++)
//		{
//			printf("%c",i);
//		}
//	}
//	if(t!=' ') printf("%c",t);
//	for(int i='z';i>='a';i--)
//	{
//		for(int j=0;j<s[i]/2;j++)
//		{
//			printf("%c",i);
//		}
//	}
	return 0;
}