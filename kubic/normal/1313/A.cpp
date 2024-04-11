#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,t,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d %d %d",&a,&b,&c);
		if(a) --a,++ans;if(b) --b,++ans;if(c) --c,++ans;
		t=max(max(a,b),c);
		if(t==a)
		{
			if(a && b) --a,--b,++ans;
			if(a && c) --a,--c,++ans;
			if(b && c) --b,--c,++ans;
		}
		if(t==b)
		{
			if(a && b) --a,--b,++ans;
			if(b && c) --b,--c,++ans;
			if(a && c) --a,--c,++ans;
		}
		if(t==c)
		{
			if(a && c) --a,--c,++ans;
			if(b && c) --b,--c,++ans;
			if(a && b) --a,--b,++ans;
		}
		if(a && b && c) ++ans;printf("%d\n",ans);
	}return 0;
}