#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 20005
#define inf 0x3f3f3f3f
#define mem(x) memset(x,0,sizeof(x))

int n,m,ans=inf;
int sum[N],rk[N],sa[N],trk[N],tmp[N],h[N],p,be[N]; 
char s[N];

void SA(){
	rep(i,1,n) trk[i]=s[i],p=trk[i]>p?trk[i]:p;
	rep(i,1,n) sum[trk[i]]++;
	rep(i,1,p) sum[i]+=sum[i-1];
	dep(i,n,1) sa[sum[trk[i]]--]=i;
	rk[sa[1]]=1;
	for(int i=2,j=1;i<=n;++i){
		if(trk[sa[i]]^trk[sa[i-1]]) ++j;
		rk[sa[i]]=j;
	}
	for(int j=1;j<=n;j<<=1){
		mem(sum);
		rep(i,1,n) sum[rk[i+j]]++;
		rep(i,1,p) sum[i]+=sum[i-1];
		dep(i,n,1) tmp[sum[rk[i+j]]--]=i;
		mem(sum);
		rep(i,1,n) sum[rk[i]]++;
		rep(i,1,p) sum[i]+=sum[i-1];
		dep(i,n,1) sa[sum[rk[tmp[i]]]--]=tmp[i];
		trk[sa[1]]=p=1;
		rep(i,2,n){
			if(rk[sa[i]]^rk[sa[i-1]] || rk[sa[i]+j]!=rk[sa[i-1]+j]) ++p;
			trk[sa[i]]=p;
		}
		rep(i,1,n) rk[i]=trk[i];
	}
	for(int i=1,j=0;i<=n;++i){
		if(rk[i]==1) continue;
		for(;s[i+j]==s[sa[rk[i]-1]+j];)++j;
		h[rk[i]]=j;
		if(j) --j;
	}
}

int main(){
	scanf("%s",s+1);
	m=strlen(s+1);
	s[++m]='#';
	scanf("%s",s+m+1);
	n=strlen(s+1);
	rep(i,m+1,n) be[i]=1;
	SA();
	rep(i,2,n) if(be[sa[i-1]]^be[sa[i]] && h[i] && h[i]>h[i-1] && h[i]>h[i+1])
		ans=min(ans,max(h[i-1],h[i+1])+1);
	if(ans==inf) ans=-1;
	printf("%d\n",ans);
}