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
int n,m,a[N],b[N],r[N],c[N];
bool check(int lim,int x,int y){
	int j=m;For(i,1,n){
		while(j&&a[i]+b[j]>lim)j--;
		r[i]=j;
	}int i=n;For(j,1,m){
		while(i&&a[i]+b[j]>lim)i--;
		c[j]=i;
	}int ans=0,now=0,X=0,Y=0;
	for(int i=1,j=0;i<=n;i++){
		now+=min(r[i],j)-(m-max(r[i],j));
		while(j<m&&min(c[j+1],i)-(n-max(c[j+1],i))>=0)now+=min(c[j+1],i)-(n-max(c[j+1],i)),j++;
		if(now>=ans)ans=now,X=i,Y=j;
	}return X>=x||Y>=y;
}
signed main(){
	n=read(),m=read();For(i,1,n)a[i]=read();For(i,1,m)b[i]=read();
	int x=a[1],y=b[1];sort(a+1,a+1+n),sort(b+1,b+1+m);
	int X=1,Y=1;while(a[X]!=x)X++;while(b[Y]!=y)Y++;
	int l=1,r=a[X]+b[Y];while(r-l>1){
        int m=l+r>>1;
        if(check(m,X,Y))r=m;
        else l=m;
    }cout<<r<<endl;
	return 0;
}