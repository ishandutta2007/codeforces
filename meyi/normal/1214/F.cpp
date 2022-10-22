#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10,maxp=456;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],b[maxn],cnt,d,ida[maxn],idb[maxn],len,m,mch[maxn],n;
ll ans=LLONG_MAX;
pair<int,ll>f[maxp];
inline int dis(int x,int y){
	ri ret=abs(a[ida[x]]-b[idb[y]]);
	return min(len-ret,ret);
}
inline ll calc(int k){
	ll ret=0;
	for(ri i=1;i<=n;++i)ret+=dis(i,(i+k)%n+1);
	if(ret<ans)ans=ret,d=k;
	return ret;
}
signed main(){
	len=qr(),n=qr();
	for(ri i=1;i<=n;++i)a[i]=qr(),ida[i]=i;
	sort(ida+1,ida+n+1,[&](int x,int y){return a[x]<a[y];});
	for(ri i=1;i<=n;++i)b[i]=qr(),idb[i]=i;
	sort(idb+1,idb+n+1,[&](int x,int y){return b[x]<b[y];});
	if(n<=10000)for(ri i=0;i<n;++i)calc(i);
	else{
		m=sqrt(n);
		for(ri i=0;i<n;i+=m)f[++cnt]={i,calc(i)-calc(i+1)};
		f[++cnt]={n-1,calc(n-1)-calc(n)};
		for(ri i=1;i<cnt;++i)
			if(f[i].second>=0&&f[i+1].second<=0){
				for(ri j=f[i].first;j<f[i+1].first;++j)calc(j);
				break;
			}
	}
	qw(ans),putchar(10);
	for(ri i=1;i<=n;++i)mch[ida[i]]=idb[(i+d)%n+1];
	for(ri i=1;i<=n;++i)qw(mch[i]),putchar(32);
	return 0;
}