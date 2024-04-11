#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
int siz[maxn],f[maxn],l[maxn],r[maxn],m,n,t_case;
char s[maxn],op[maxn];
ll ans;
queue<int>q;
inline void build1(){
	q.push(n);
	ri cnt1=n,cnt2=n;
	while(q.size()){
		ri p=q.front();q.pop();
		op[p]=s[cnt2--];
		if(cnt1)r[p]=--cnt1,q.push(cnt1);
		if(cnt1)l[p]=--cnt1,q.push(cnt1);
	}
}
inline void update(int p){
	if(!l[p]&&!r[p]){
		if(op[p]=='?')siz[p]=2;
		else siz[p]=1;
		return;
	}
	if(op[p]=='?')siz[p]=siz[l[p]]+siz[r[p]];
	else{
		if(op[p]=='0')siz[p]=siz[l[p]];
		if(op[p]=='1')siz[p]=siz[r[p]];
	}
}
inline void build2(int p){
	if(!l[p]&&!r[p]){
		if(op[p]=='?')siz[p]=2;
		else siz[p]=1;
		return;
	}
	f[l[p]]=p;
	build2(l[p]);
	f[r[p]]=p;
	build2(r[p]);
	update(p);
}
inline void modify(int pos,char x){
	op[pos]=x;
	update(pos);
	while(f[pos])pos=f[pos],update(pos);
}
int main(){
	scanf("%d%s",&n,s+1);
	n=(1<<n)-1;
	build1();
	build2(n);
	scanf("%d",&m);
	while(m--){
		ri pos;
		char x[5];
		scanf("%d%s",&pos,x);
		modify(pos,*x);
		printf("%d\n",siz[n]);
	}
	return 0;
}