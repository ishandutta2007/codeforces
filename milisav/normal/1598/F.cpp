#include<bits/stdc++.h>
#define maxn 22
#define maxs 500000
using namespace std;
int n;
char s[maxn][maxs];
int l[maxn];
int mp[maxn][2*maxs];
int sm[maxn];
int mn[maxn];
int dp[1<<maxn];
bool fin[1<<maxn];
int cm[maxn];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%s",s[i]);
		l[i]=strlen(s[i]);
		//mp[i][l[i]]=1;
		int cur=l[i];
		mn[i]=l[i];
		for(int j=0;j<l[i];j++) {
			if(s[i][j]=='(') cur+=1;
			else cur-=1;
			if(mn[i]>=cur) mp[i][cur]+=1;
			mn[i]=min(mn[i],cur);
		}
		sm[i]=cur-l[i];
		mn[i]-=l[i];
	}
	int ans=0;
	for(int msk=1;msk<(1<<n);msk++) {
		int m=0;
		int tots=0;
		fin[msk]=true;
		for(int i=0;i<n;i++) {
			if(msk&(1<<i)) {
				cm[m++]=i;
				tots+=sm[i];
			}
		}
		for(int j=0;j<m;j++) {
			int i=cm[j];
			int wmsk=(msk^(1<<i));
			if(fin[wmsk]) continue;
			int vl=l[i]-(tots-sm[i]);
			int cur=dp[wmsk];
			if(vl>=0 && vl<=2*l[i]) {
				cur+=mp[i][vl];
			}
			ans=max(ans,cur);
			if(tots-sm[i]+mn[i]>=0) {
				fin[msk]=false;
				dp[msk]=max(dp[msk],cur);
			}
		}
	}
	printf("%d",ans);
	return 0;
}