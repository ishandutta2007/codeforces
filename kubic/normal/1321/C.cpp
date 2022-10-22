#include <bits/stdc++.h>
using namespace std;
#define N 105
int n,ans,nw,t,tmp;char a[N];bool vs[N];
int main()
{
	scanf("%d %s",&n,a+1);nw=n;
	for(int i=25;i>=1;--i)
	{
		t=tmp=0;for(int j=1;j<=nw;++j) vs[j]=0;
		for(int j=1;j<=nw+1;++j) if(a[j]-'a'!=i)
		{
			if(a[t]-'a'==i-1 || a[j]-'a'==i-1)
				for(int k=t+1;k<j;++k) vs[k]=1,++ans;t=j;
		}for(int j=1;j<=nw;++j) if(!vs[j]) a[++tmp]=a[j];
		a[tmp+1]=0;nw=tmp;
	}printf("%d\n",ans);return 0;
}