#include<bits/stdc++.h>
#define int long long
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T x,int l,int r){for(int i=l;i<=r;i++)print(x[i]," \n"[i==r]);}
const int N=1e6+10;
int n,a[N];
long long ans[N],s[N],f[N],lst,sum;
inline long long calc(int l,int r){return l>r?0:(long long)(l+r)*(r-l+1)/2;}
inline void add(int k,int x,long long *s){if(k==0){s[0]+=x;return;}for(;k<=n;k+=k&-k)s[k]+=x;}
inline long long ask(int k,long long *s){long long r=s[0];for(;k;k-=k&-k)r+=s[k];return r;}
inline int search(int ss){
	int l=1,r=n,res=-1;
	while(l<=r){
		int mid=(l+r)>>1,t=ask(mid,s);
		t>=ss-t?(r=mid-1,res=mid):(l=mid+1);
	}
	return res;
}
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1,x;i<=n;i++)read(x),a[x]=i;
	for(int i=1,k;i<=n;i++){
		add(a[i],1,s),add(a[i],a[i],f);
		k=search(i);
		// printf("%d %d >> %d\n",i,a[i],k);
		sum-=ask(a[i]-1,s);
		lst+=i-ask(a[i],s);
		ans[i]+=lst;
		int ll=(i&1)?i>>1:(i>>1)-1;
		int rr=i-ll-1;
		ans[i]+=calc(k-ll,k-1)-ask(k-1,f);
		ans[i]+=ask(n,f)-ask(k,f)-calc(k+1,k+rr);
		// printf(">> %d | %d %d | %d %d %d %d\n",i-ask(a[i],s),ll,rr,calc(k-ll,k-1),ask(k-1,f),ask(n,f)-ask(k,f),calc(k+1,k+rr));
		sum+=(n-a[i])-(i-ask(a[i],s));
	}
	for(int i=1;i<=n;i++)print(ans[i]," \n"[i==n]);
}