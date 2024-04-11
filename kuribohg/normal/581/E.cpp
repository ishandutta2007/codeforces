#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
const int MAXN=200010;
typedef long long LL;
typedef pair<int,LL> PIL;
int n,m,cnt[4][MAXN<<2];
LL e,s,Q[MAXN],S[4][MAXN<<2];
PIL P[MAXN];
vector<LL> A;
int main()
{
	scanf("%I64d%I64d%d%d",&e,&s,&n,&m);
	A.push_back(e);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%I64d",&P[i].first,&P[i].second);
		A.push_back(P[i].second);
		A.push_back(P[i].second+s);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&Q[i]);
		A.push_back(Q[i]+s);
	}
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	for(int i=1;i<=n;i++)
	{
		int l=lower_bound(A.begin(),A.end(),P[i].second)-A.begin();
		int r=lower_bound(A.begin(),A.end(),P[i].second+s)-A.begin();
		for(int k=1;k<=P[i].first;k++) cnt[k][l]++,cnt[k][r]--;
	}
	for(int k=1;k<=3;k++)
	{
		for(int i=1;i<A.size();i++) cnt[k][i]+=cnt[k][i-1];
		for(int i=1;i<A.size();i++) S[k][i]=S[k][i-1]+(cnt[k][i-1]>0?A[i]-A[i-1]:0);
	}
	int T=lower_bound(A.begin(),A.end(),e)-A.begin();
	for(int i=1;i<=m;i++)
	{
		int x=lower_bound(A.begin(),A.end(),Q[i]+s)-A.begin();
		LL ans1,ans2;
		if(x>=T) ans1=0,ans2=0;
		else
		{
			LL dis=A[T]-A[x];
			LL dis3=S[3][T]-S[3][x];
			LL dis2=S[2][T]-S[2][x];
			LL dis1=S[1][T]-S[1][x];
			if(dis==dis3) ans1=0,ans2=0;
			else if(dis==dis2) ans1=0,ans2=dis-dis3;
			else if(dis==dis1) ans1=dis-dis2,ans2=dis-dis3-ans1;
			else ans1=-1,ans2=-1;
		}
		printf("%I64d %I64d\n",ans1,ans2);
	}
	return 0;
}