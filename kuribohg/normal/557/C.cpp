#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=200010;
pair<int,int> A[MAXN];
int n,x,c[300],L,R,ans=2000000000,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x),A[i].first=x;
	for(int i=1;i<=n;i++) scanf("%d",&x),A[i].second=x,sum+=x;
	sort(A+1,A+n+1);
	L=1;
	while(L<=n)
	{
		int R=L;
		while(A[R+1].first==A[L].first&&R+1<=n) R++;
		int cnt=L-1-(R-L);
		for(int i=L;i<=R;i++) sum-=A[i].second;
		int res=sum;
		if(cnt<0) cnt=0;
		for(int i=1;i<=200;i++)
		{
			if(cnt>=c[i]) res+=i*c[i],cnt-=c[i];
			else res+=cnt*i,cnt=0;
		}
		ans=min(ans,res);
		for(int i=L;i<=R;i++) c[A[i].second]++;
		L=R+1;
	}
	printf("%d\n",ans);
	return 0;
}