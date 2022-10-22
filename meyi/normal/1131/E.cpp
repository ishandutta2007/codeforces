#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=1e9,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct node{
	ll len,mx,pre,suf;
	inline void init(const vector<char> &s,int len_,char ch){
		len=len_;
		for(pre=1;pre<=len&&s[pre]==ch;++pre);--pre;
		for(suf=len;suf&&s[suf]==ch;--suf);suf=len-suf;
		mx=0;
		for(ri i=1,lst=0;i<=len;++i)
			if(s[i]==ch)ckmax(mx,(ll)i-lst);
			else lst=i;
	}
	inline void operator*=(const node &k){
		if(len==mx&&k.len==k.mx)mx=pre=suf=(len+=(len+1)*k.len);
		else{
			if(k.len==k.mx){
				mx+=(mx+1)*k.mx;
				pre+=(pre+1)*k.mx;
				suf+=(suf+1)*k.mx;
			}
			else{
				ll tmp=0;
				if(mx)ckmax(tmp,k.suf+1+k.pre);
				ckmax(tmp,k.mx);
				mx=tmp;
				pre=k.pre;
				suf=k.suf;
			}
			len+=(len+1)*k.len;
		}
		ckmin(mx,(ll)inf);
	}
}a[maxn];
ll ans;
int len[maxn],n;
vector<char>s[maxn];
char t[maxn];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%s",t+1);
		len[i]=strlen(t+1);
		s[i]={0};
		for(ri j=1;j<=len[i];++j)s[i].push_back(t[j]),t[j]=0;
	}
	for(char ch='a';ch<='z';++ch){
		a[1].init(s[1],len[1],ch);
		for(ri i=2;i<=n;++i){
			a[i].init(s[i],len[i],ch);
			a[1]*=a[i];
		}
		ckmax(ans,a[1].mx);
	}
	printf("%lld",ans);
	return 0;
}