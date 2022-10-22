#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int main()
{
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&q);
		int k;
		set<int> s,t;
		for(int j=1;j<=q;j++)
		{
			scanf("%d",&k);
			if(k>0) s.insert(k);
			if(k<0) t.insert(k);
		}
		q=s.size()+t.size();
		set<int>::iterator it;
		for(it=t.begin();it!=t.end();it++) s.insert(abs(*it));
		if(s.size()==q) ans++;
	}
	if(ans>0) printf("YES\n");
	else printf("NO\n");
	return 0;
}