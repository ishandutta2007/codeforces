#include <bits/stdc++.h>
using namespace std;
int T,m1,m2,c1,c2,w1,w2,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d %d",&m1,&m2,&c1,&c2,&w1,&w2);
		if(w1>w2) swap(c1,c2),swap(w1,w2);ans=0;
		if(m1/w1+m2/w1<=c1) {printf("%d\n",m1/w1+m2/w1);continue;}
		for(int i=0;i<=c1;++i) if(m1>=i*w1 && m2>=(c1-i)*w1)
			ans=max(ans,c1+min(c2,(m1-i*w1)/w2+(m2-(c1-i)*w1)/w2));printf("%d\n",ans);
	}return 0;
}