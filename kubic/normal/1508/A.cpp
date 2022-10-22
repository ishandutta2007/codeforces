#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,t1,t2,t3,cnt[2];
char a1[N*2],a2[N*2],a3[N*2];
void slv()
{
	scanf("%d %s %s %s",&n,a1+1,a2+1,a3+1);
	t1=t2=t3=1;
	for(int i=1;i<=n*3;++i)
	{
		char c;cnt[0]=cnt[1]=0;
		if(t1<=n*2) ++cnt[a1[t1]-'0'];
		if(t2<=n*2) ++cnt[a2[t2]-'0'];
		if(t3<=n*2) ++cnt[a3[t3]-'0'];
		if(cnt[0]+cnt[1]>2)
		{if(cnt[0]>cnt[1]) c='0';else c='1';}
		else
		{
			int mx=0;
			if(t1<=n*2) mx=max(mx,t1);
			if(t2<=n*2) mx=max(mx,t2);
			if(t3<=n*2) mx=max(mx,t3);
			if(t1==mx) c=a1[t1];
			else if(t2==mx) c=a2[t2];
			else if(t3==mx) c=a3[t3];
			else c='0';
		}
		if(a1[t1]==c) ++t1;
		if(a2[t2]==c) ++t2;
		if(a3[t3]==c) ++t3;
		putchar(c);
	}puts("");
}
int main()
{
	scanf("%d",&T);while(T--) slv();
	return 0;
}