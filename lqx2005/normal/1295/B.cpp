#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
const int inf=100000000;
int T;
int n,x;
char s[maxn+5];
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		int cnt=0;
		vector<int> t;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1') cnt--;
			else cnt++;
			t.push_back(cnt);
		}
		sort(t.begin(),t.end());
		t.push_back(inf);
		if(!cnt)
		{
			int pos=lower_bound(t.begin(),t.end(),x)-t.begin();
			if(t[pos]==x) printf("-1\n");
			else printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<t.size()-1;i++)
		{
			int det=x-t[i];
			if(det%cnt) continue;
			det/=cnt;
			if(det<0) continue;
			ans++;
		}
		if(!x) ans++;
		printf("%d\n",ans);
	}
	return 0;
}