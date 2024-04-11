#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=100010;
int n,ans;
pair<int,int> A[MAXN];
int Sta1[MAXN],top1;
int Sta2[MAXN],top2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i].first,&A[i].second);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++) if(A[i].first>0) Sta1[++top1]=i;
	for(int i=n;i>=1;i--) if(A[i].first<0) Sta2[++top2]=i;
	int x=min(top1,top2);
	for(int i=1;i<=x;i++) ans+=A[Sta1[i]].second+A[Sta2[i]].second;
	ans+=max(A[Sta1[x+1]].second,A[Sta2[x+1]].second);
	printf("%d\n",ans);
	return 0;
}