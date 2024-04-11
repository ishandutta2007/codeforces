#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
static char obuf[1000000],*o=obuf;
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int cnt[maxn],fac[maxn];
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])fac[i]=1,pri.push_back(i);
		for(ri j:pri){
			ri k=i*j;
			if(k>siz)break;
			fac[k]=i;
			vis[k]=true;
			if(i%j==0)break;
		}
		++cnt[fac[i]];
	}
}
int n;
int main(){
	scanf("%d",&n);
	sieve(n);
	for(ri i=1;i<=n;++i)
		while(cnt[i]--)
			qw(i),putchar(32);
	return 0;
}