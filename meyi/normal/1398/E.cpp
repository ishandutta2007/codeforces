#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
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
	if(out<0)putchar('-'),out=-out;
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
set<int,greater<int>>a;
set<int>s,t;
int cnt,n;
ll sum;
inline void check(){
	if(t.size()<cnt&&a.size())sum+=*a.begin(),t.insert(*a.begin()),a.erase(a.begin());
	if(t.size()>cnt)sum-=*t.begin(),a.insert(*t.begin()),t.erase(t.begin());
}
inline void insert(int k){
	if(a.size()&&k<*a.begin()){
		ri tmp=*a.begin();
		a.erase(a.begin());
		a.insert(k);
		k=tmp;
	}
	if(t.size()<cnt)sum+=k,t.insert(k);
	else{
		if(t.size()&&k>*t.begin()){
			ri tmp=*t.begin();
			sum+=k-tmp;
			t.erase(t.begin());
			t.insert(k);
			k=tmp;
		}
		a.insert(k);
	}
	check();
}
inline void erase(int k){
	if(t.empty()||k<*t.begin())a.erase(k);
	else sum-=k,t.erase(k);
	check();
}
int main(){
	n=qr();
	for(ri i=1,op,x;i<=n;++i){
		op=qr(),x=qr();
		int sgn=(x<0?-1:1);
		sum+=x;
		if(op){
			if(~sgn){
				++cnt;
				if(s.size()){
					if(x>*s.begin())insert(x);
					else insert(*s.begin());
				}
				else check();
				s.insert(x);
			}
			else{
				--cnt;
				s.erase(-x);
				if(s.size()){
					if(-x>*s.begin())erase(-x);
					else erase(*s.begin());
				}
				else check();
			}
		}
		else{
			if(~sgn)insert(x);
			else erase(-x);
		}
		qw(sum),putchar(10);
	}
	return 0;
}