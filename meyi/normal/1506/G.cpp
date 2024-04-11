#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int pre[maxn][26],n,suf[maxn][26],t_case;
char s[maxn];
bool ex[maxn];
inline bool check(int k){
	for(ri i=0;i<26;++i)
		if(ex[i]&&!suf[k][i])
			return false;
	return true;
}
inline int half(int pos){
	ri ans=0,l=1,r=n,ret=-1;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	for(ri i=25;~i;--i)
		if(ex[i]&&pre[ret][i]>pos){
			ans=pre[ret][i];
			while(pre[ans-1][i]>pos)ans=pre[ans-1][i];
			break;
		}
	ex[s[ans]]=false;
	putchar(s[ans]+'a');
	return ans;
}
int main(){
	scanf("%d",&t_case);
	s[0]=-1;
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=0;i<26;++i)suf[n+1][i]=0;
		for(ri i=1;i<=n;++i){
			s[i]-='a';
			ex[s[i]]=true;
			for(ri j=0;j<26;++j)pre[i][j]=pre[i-1][j];
			pre[i][s[i]]=i;
		}
		for(ri i=n;i;--i){
			for(ri j=0;j<26;++j)
				suf[i][j]=suf[i+1][j];
			++suf[i][s[i]];
		}
		ri pos=0,tot=0;
		for(ri i=0;i<26;++i)tot+=ex[i];
		while(tot--)pos=half(pos);
		putchar(10);
	}
}