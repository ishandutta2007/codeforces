#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10;
struct node{
	int x,y,op;
	bool operator < (const node &a) const {
		return x==a.x?(y<a.y):x<a.x;
	}
}a[N<<1];
int ans[N],t[N],m;
map<int,map<int,int>> mp;
int del[N];
#define lowbit(x) (x&-x)
int c[N],delx[N],h[N],k;
void add(int u,int v){for(int i=u;i<N;i+=lowbit(i))c[i]+=v;}
int ask(int u,int s=0){for(int i=u;i;i-=lowbit(i))s+=c[i];return s;}
signed main(){
	int n=read(),q=read();
	For(i,1,n){
		int x=read(),y=read();
		a[i]=(node){x,y,0},t[++m]=y,h[++k]=x;
	}For(i,1,q){
		int x=read(),y=read();
		a[i+n]=(node){x,y,i},t[++m]=y,h[++k]=x;
	}
	sort(t+1,t+1+m),m=unique(t+1,t+1+m)-t-1;
	sort(h+1,h+1+k),k=unique(h+1,h+1+k)-h-1;
	For(i,1,n+q){
		if(i<=n)mp[a[i].x][a[i].y]=1;
	}sort(a+1,a+1+n+q);int d=0;For(i,1,n+q){
		int x=a[i].x,y=a[i].y,id=a[i].op,pos=lower_bound(t+1,t+1+m,y)-t,px=lower_bound(h+1,h+1+k,x)-h;
		int nd=d-ask(pos);
		if(!id){
			if(x<y+nd){
				if(del[pos]);
				else del[pos]=1,add(pos,1);
			}if(x>y+nd){
				if(delx[px]);
				else delx[px]=1,d++;
			}
		}else{
			if(mp[x][y])ans[id]=0;
			else if(delx[px]||del[pos])ans[id]=1;
			else ans[id]=x!=y+nd;
		}
	}For(i,1,q)puts(ans[i]?"WIN":"LOSE");
	return 0;
}//fasds