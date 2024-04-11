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
const int N=3e5+10;
int n,k;char a[N];
int fa[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void merge(int x,int y){fa[get(x)]=get(y);}
signed main(){
	int T=read();while(T--){
		n=read(),k=read(),scanf("%s",a+1);
		For(i,0,n+1)fa[i]=i;For(i,1,n){
			if(i+k<=n)merge(i,i+k);
			if(a[i]=='1')merge(i,0);
			if(a[i]=='0')merge(i,n+1);
		}int fl=get(0)==get(n+1);
		For(i,1,n)if(a[i]=='?'){
			if(get(i)==get(0))a[i]='1';
			if(get(i)==get(n+1))a[i]='0';
		}
//		For(i,1,n)putchar(a[i]);puts("done");
		int c0=0,c1=0;For(i,1,k)
			c0+=a[i]=='0',c1+=a[i]=='1';
		fl|=c0*2>k||c1*2>k;
		For(i,k+1,n){
			c0-=a[i-k]=='0',c1-=a[i-k]=='1';
			c0+=a[i]=='0',c1+=a[i]=='1';
			fl|=c0*2>k||c1*2>k;
		}
		puts(fl?"NO":"YES");
	}
	return 0;
}