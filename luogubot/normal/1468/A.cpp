#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10;
int n,a[N],c[N],f[N]; 
inline void gmax(int &a,int b){(a<b)&&(a=b);}
struct node{
	int pos,val;
	bool operator < (const node &x) const {
		return pos>x.pos;
	}
};priority_queue<node> q;
#define lowbit(x) (x&-x)
void add(int u,int v){for(int i=u;i<=n;i+=lowbit(i))gmax(c[i],v);}
int ask(int u,int s=0){for(int i=u;i;i-=lowbit(i))gmax(s,c[i]);return s;}
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())a[i]=read(),c[i]=f[i]=0;while(!q.empty())q.pop();
		int ans=0,mx=0;For(i,1,n){
			f[i]=ask(a[i])+1;
			if(mx>=a[i])gmax(f[i],2);gmax(mx,a[i]);
			gmax(ans,f[i]);
//			printf("f[%d] = %d\n",i,f[i]);
			while(!q.empty()&&q.top().pos<=a[i]){
				int p=q.top().pos,u=q.top().val;q.pop();
				add(p,f[u]+1);
			}q.push((node){a[i],i}),add(a[i],f[i]);
		}cout<<ans<<endl;
	}
	return 0;
}