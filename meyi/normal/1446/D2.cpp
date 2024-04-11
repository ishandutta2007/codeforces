#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],ans,cnt[maxn],lim,lst[maxn<<1],mx,mxx,n,val;
inline int calc(int k){
	memset(lst,-1,sizeof lst);
	lst[0+maxn]=0;
	ri ret=0,sum=0;
	for(ri i=1;i<=n;++i){
		if(a[i]==mx)++sum;
		if(a[i]==k)--sum;
		if(lst[sum+maxn]!=-1)ckmax(ret,i-lst[sum+maxn]);
		else lst[sum+maxn]=i;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		++cnt[a[i]];
		if(cnt[a[i]]>val)mx=a[i],mxx=0,val=cnt[a[i]];
		else if(a[i]!=mx&&cnt[a[i]]==val)mxx=a[i];
	}
	if(mxx)return printf("%d",n),0;
	lim=sqrt(n);
	for(ri i=1;i<200001;++i)
		if(cnt[i]>lim&&i!=mx)
			ckmax(ans,calc(i));
	for(ri i=1;i<=lim;++i){
		memset(cnt,0,sizeof cnt);
		for(ri l=1,r=0,tmp=0;l<=n;++l){
			while(r<n&&cnt[a[r+1]]<i){
				++r;
				if(cnt[a[r]]==i)--tmp;
				++cnt[a[r]];
				if(cnt[a[r]]==i)++tmp;
			}
			if(tmp>=2)ckmax(ans,r-l+1);
			if(cnt[a[l]]==i)--tmp;
			--cnt[a[l]];
			if(cnt[a[l]]==i)++tmp;
		}
	}
	printf("%d",ans);
	return 0;
}