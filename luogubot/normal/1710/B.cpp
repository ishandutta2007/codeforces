#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n,m,p[N],sum[N],ret[N],S;
multiset<int> s;
struct node{
	int x,p,i;
	bool operator < (const node &a) const {
		if(x!=a.x)return x<a.x;
		if(p!=a.p)return p<a.p;
		return i<a.i;
	}
}a[N];
void init(){
	S=0,s.clear();
	For(i,0,n+1)sum[i]=0,ret[i]=0;
	For(i,1,n)a[i].x=a[i].p=a[i].i=0;
}int d[N];
void work1(){
	s.clear(),S=0;
	For(i,1,n){
		if(i>1){
			while(!s.empty()){
				int v=*s.begin();if(v>a[i].x)break;
				S+=a[i-1].x-v,s.erase(s.find(v));
			}S-=s.size()*d[i];
		}s.insert(a[i].x+a[i].p),S+=a[i].p,sum[i]+=S;
	}
}
void work2(){
	s.clear(),S=0;
	Rof(i,n,1){
		if(i<n){
			while(!s.empty()){
				int v=*s.begin();if(-v<a[i].x)break;
				S-=a[i+1].x+v,s.erase(s.find(v));
			}S-=s.size()*d[i+1];
		}s.insert(a[i].p-a[i].x),sum[i]+=S,S+=a[i].p;
	}
}
void calc1(){int now=-1e18;For(i,1,n)now+=d[i],now=sum[i]>0?max(now,sum[i]):now,ret[i]=max(ret[i],now);}
void calc2(){int now=-1e18;Rof(i,n,1)now+=d[i+1],now=sum[i]>0?max(now,sum[i]):now,ret[i]=max(ret[i],now);}
signed main(){
	int T=read();while(T--){
		n=read(),m=read(),init();
		For(i,1,n){
			int x=read(),p=read();
			a[i]=(node){x,p,i};
		}sort(a+1,a+1+n);For(i,1,n)p[a[i].i]=i,d[i]=a[i].x-a[i-1].x;d[n+1]=1e9;
		work1(),work2();For(i,1,n)sum[i]=sum[i]<=m?0ll:sum[i]-m;
		calc1(),calc2();For(i,1,n)putchar(a[p[i]].p<ret[p[i]]?'0':'1');puts("");
	}
	return 0;
}