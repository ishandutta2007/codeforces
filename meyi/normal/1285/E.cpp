#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=8e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;bool f=false;char ch;
	while(!isdigit(ch=getchar()))f|=(ch=='-');
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return f?-in:in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int all,ans[maxn],b[maxn],bl,cnt[maxn],l[maxn],mx,n,r[maxn],t_case;
int main(){
	t_case=qr();
	while(t_case--){
		n=qr();
		bl=0;
		for(ri i=1;i<=n;++i)b[++bl]=l[i]=qr(),b[++bl]=r[i]=qr();
		sort(b+1,b+bl+1);
		bl=unique(b+1,b+bl+1)-b-1;
		for(ri i=1;i<=n;++i){
			l[i]=((lower_bound(b+1,b+bl+1,l[i])-b)<<1)-1;
			r[i]=((lower_bound(b+1,b+bl+1,r[i])-b)<<1)-1;
			++cnt[l[i]],--cnt[r[i]+1];
		}
		all=0;
		bl<<=1;
		for(ri i=1;i<=bl;++i){
			cnt[i]+=cnt[i-1];
			if(!cnt[i-1]&&cnt[i])++all;
			if(cnt[i-1]!=1&&cnt[i]==1)++ans[i];
			if(cnt[i-1]==1&&cnt[i]!=1)++ans[i-1];
		}
		for(ri i=1;i<=bl;++i)ans[i]+=ans[i-1];
		mx=INT_MIN;
		for(ri i=1;i<=n;++i)ckmax(mx,(ans[r[i]]-ans[l[i]-1]>>1)-(cnt[l[i]]==1)-(cnt[r[i]]==1));
		qw(all+mx),putchar(10);
		if(t_case)clear(ans,bl),clear(cnt,bl);
	}
	return 0;
}