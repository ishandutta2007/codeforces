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
int ax,ay,bx,by;
int X[100],Y[100],m;
int get(int x,int y,int t,int l,int r){
	int xx=x,yy=y,tt=t,cc=0,ret=0;
	For(i,l,r){
		int val=abs(xx-X[i])+abs(yy-Y[i]);
		if(tt<val)break;tt-=val,xx=X[i],yy=Y[i],cc++;
	}ret=cc,xx=x,yy=y,tt=t,cc=0;
	Rof(i,r,l){
		int val=abs(xx-X[i])+abs(yy-Y[i]);
		if(tt<val)break;tt-=val,xx=X[i],yy=Y[i],cc++;
	}return max(ret,cc);
}
signed main(){
	int x=read(),y=read();ax=read(),ay=read(),bx=read(),by=read();
	int x0=read(),y0=read(),t=read();
	int ans=0;
	For(i,1,55){
		m++,X[m]=x,Y[m]=y;
		if(x>1e16||y>1e16)break;
		x=ax*x+bx,y=ay*y+by;
	}For(l,1,m)For(r,l,m)ans=max(ans,get(x0,y0,t,l,r));
	cout<<ans<<endl;
	return 0;
}