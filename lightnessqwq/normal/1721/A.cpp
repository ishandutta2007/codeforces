#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int cnt[256];
string s,t;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s>>t,cnt[s[0]]++,cnt[s[1]]++,cnt[t[0]]++,cnt[t[1]]++;
		int res=max(cnt[s[0]],max(cnt[s[1]],max(cnt[t[0]],cnt[t[1]])));
		int mn=min(cnt[s[0]],min(cnt[s[1]],min(cnt[t[0]],cnt[t[1]])));
		if(res==4)
			puts("0");
		else if(res==3||(res==2&&mn==2))
			puts("1");
		else if(res==2)
			puts("2");
		else if(res==1)
			puts("3");
		cnt[s[0]]--,cnt[s[1]]--,cnt[t[0]]--,cnt[t[1]]--;
	}
	return 0;
}