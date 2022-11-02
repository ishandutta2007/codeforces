// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000003;
int n,i,j,k,d[N],b[N],c[N],rnk[N],sa[N],cnt[N],p,h[N],ans;
char s[N];
bool cmp(int x,int y){
	return s[x]<s[y];
}
int main(){
	scanf("%s",s+1);
	while(s[n+1]){n++;sa[n]=n;}
	sort(sa+1,sa+n+1,cmp);
	for(i=1;i<=n;i++)
		rnk[sa[i]]=rnk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
	p=rnk[sa[n]];
	for(k=0;(1<<k)<n&&p<n;k++){
		for(i=0;i<=p;i++) cnt[i]=0;
		for(i=1;i<=n;i++) cnt[1+(d[i]=i+(1<<k)<=n?rnk[i+(1<<k)]:0)]++;
		for(i=1;i<=p;i++) cnt[i]+=cnt[i-1];
		for(i=1;i<=n;i++) sa[++cnt[d[i]]]=i;
		for(i=0;i<=p;i++) cnt[i]=0;
		for(i=1;i<=n;i++) cnt[1+rnk[i]]++,b[i]=rnk[i],c[i]=d[i],d[i]=sa[i];
		for(i=1;i<=p;i++) cnt[i]+=cnt[i-1];
		for(i=1;i<=n;i++) sa[++cnt[rnk[d[i]]]]=d[i];
		for(i=1;i<=n;i++) rnk[sa[i]]=rnk[sa[i-1]]+((b[sa[i]]!=b[sa[i-1]])||(c[sa[i]]!=c[sa[i-1]]));
		p=rnk[sa[n]];
	}
	for(i=1;i<=n;i++){
		h[i]=max(h[i-1]-1,0);
		while(s[i+h[i]]==s[sa[rnk[i]-1]+h[i]])
			h[i]++;
		ans=max(ans,h[i]);
	}
	printf("%d",ans);
	//while(1);
}