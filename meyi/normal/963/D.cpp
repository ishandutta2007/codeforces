#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
bitset<maxn>ans,b[26];
int k,m,n,q;
char s[maxn],t[maxn];
signed main(){
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	for(ri i=1;i<=n;++i)b[s[i]-'a'].set(i);
	while(q--){
		scanf("%d%s",&k,t+1);
		m=strlen(t+1);
		ans.set();
		for(ri i=1;i<=m;++i)ans&=b[t[i]-'a']>>i-1;
		ri cnt=ans.count();
		if(cnt<k)puts("-1");
		else{
			ri mn=INT_MAX;
			vector<int>pos;
			pos.reserve(cnt);
			for(ri i=ans._Find_first(),j=0;i<maxn;i=ans._Find_next(i),++j){
				pos.push_back(i);
				if(pos.size()>=k)mn=min(mn,m+pos[j]-pos[j-k+1]);
			}
			printf("%d\n",mn);
		}
	}
	return 0;
}