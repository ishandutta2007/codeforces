#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out<0)putchar('-'),out=-out;
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
inline char gc(){
	char ch;
	while(!isupper(ch=getchar()));
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct node{
	int id,pos;
	char ch;
	inline bool operator<(const node &k)const{
		return pos<k.pos;
	}
}a[maxn];
int ans[maxn],m,n,st[maxn],tp,t_case;
inline int calcRL(int x,int y){return (y-x)>>1;}
inline int calcLL(int x,int y){return (x+y)>>1;}
inline int calcRR(int x,int y){return (m-x+m-y)>>1;}
inline int calcLR(int x,int y){return (x+m-y+m)>>1;}
inline void solve(vector<int> &v){
	queue<int>L,R;
	tp=0;
	for(auto i:v)
		if(a[i].ch=='L'){
			if(tp)ans[a[st[tp]].id]=ans[a[i].id]=calcRL(a[st[tp]].pos,a[i].pos),--tp;
			else L.push(i);
		}
		else st[++tp]=i;
	for(ri i=tp;i;--i)R.push(st[i]);
	while(L.size()>1){
		ri x=L.front();L.pop();
		ri y=L.front();L.pop();
		ans[a[x].id]=ans[a[y].id]=calcLL(a[x].pos,a[y].pos);
	}
	while(R.size()>1){
		ri x=R.front();R.pop();
		ri y=R.front();R.pop();
		ans[a[x].id]=ans[a[y].id]=calcRR(a[x].pos,a[y].pos);
	}
	if(L.size()&&R.size())ans[a[L.front()].id]=ans[a[R.front()].id]=calcLR(a[L.front()].pos,a[R.front()].pos);
	else if(L.size())ans[a[L.front()].id]=-1;
	else if(R.size())ans[a[R.front()].id]=-1;
}
signed main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr();
		for(ri i=1;i<=n;++i)a[i].id=i,a[i].pos=qr();
		for(ri i=1;i<=n;++i)a[i].ch=gc();
		sort(a+1,a+n+1);
		vector<int>even,odd;
		for(ri i=1;i<=n;++i)((a[i].pos&1)?odd:even).push_back(i);
		solve(even),solve(odd);
		for(ri i=1;i<=n;++i)qw(ans[i]),putchar(32);
		putchar(10);
	}
	return 0;
}