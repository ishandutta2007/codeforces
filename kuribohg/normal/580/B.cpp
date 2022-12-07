#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,d,R;
LL s[MAXN],ans;
pair<int,int> p[MAXN];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+p[i].second;
	for(int L=1;L<=n;L++)
	{
		R=max(L,R);
		while(R+1<=n&&p[R+1].first-p[L].first<d) R++;
		ans=max(ans,s[R]-s[L-1]);
	}
	printf("%I64d\n",ans);
	return 0;
}