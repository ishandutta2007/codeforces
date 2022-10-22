#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char obuf[1000000],*o=obuf;
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
template<class T>
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int inv[maxn],n;
inline bool check(){
	for(ri i=2,j=sqrt(n);i<=j;++i)
		if(n%i==0)
			return false;
	return true;
}
int main(){
	scanf("%d",&n);
	if(n==1)return ps("YES\n",49),0;
	if(n==4)return ps("YES\n1\n3\n2\n",52),0;
	if(check()){
		ps("YES");
		inv[1]=1;
		for(ri i=2;i<=n;++i)inv[i]=1ll*(n-n/i)*inv[n%i]%n;
		ps("1");
		for(ri i=1;i+1<n;++i)qw(1ll*i*inv[i+1]%n),putchar(10);
		qw(n);
	}
	else ps("NO");
	return 0;
}