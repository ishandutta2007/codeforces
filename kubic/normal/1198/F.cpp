#include <bits/stdc++.h>
using namespace std;
#define N 100005
mt19937 rand1(998244353);
int n,B,w1,w2,a[N],b[N],ans[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d",&n);B=min(1e7/n,1e4*n);
	for(int i=1;i<=n;++i) b[i]=i,scanf("%d",&a[i]);
	for(int i=1,t1,t2;i<=B;++i)
	{
		bool fl1,fl2;w1=w2=0;shuffle(b+1,b+n+1,rand1);
		for(int j=1;j<=n;++j)
		{
			t1=gcd(w1,a[b[j]]);t2=gcd(w2,a[b[j]]);
			fl1=!w1 || t1<w1;fl2=!w2 || t2<w2;
			if(!fl2) w1=t1,ans[b[j]]=i;else if(!fl1) w2=t2;
			else if(rand1()&1) w1=t1,ans[b[j]]=i;else w2=t2;
		}
		if(w1==1 && w2==1)
		{
			puts("YES");
			for(int j=1;j<=n;++j)
				printf("%d ",(ans[j]==i)+1);return 0;
		}
	}puts("NO");return 0;
}