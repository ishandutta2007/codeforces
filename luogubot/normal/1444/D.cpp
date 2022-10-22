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
const int N=1e6+10,M=1e3+10;
int n,m,l[M],p[M];
bitset<N> f[M];
struct Point{
	int x,y;
	Point(){x=y=0;}
	Point(int X,int Y){x=X,y=Y;}
	int operator ^ (const Point &b) const {
		return x*b.y-b.x*y;
	}
	int qua(){
		if(x>=0&&y>0)return 1;
		if(x<0&&y>=0)return 2;
		if(x<=0&&y<0)return 3;
		if(x>0&&y<=0)return 4;
	}
}a[M];
bool cmp(Point a,Point b){
	return a.qua()==b.qua()?((a^b)>0):a.qua()<b.qua();
}
signed main(){
	int TTT=read();while(TTT--){
		int s1=0,s2=0,now=0;
		For(i,1,n=read())s1+=l[i]=read();
		For(i,1,m=read())s2+=p[i]=read();
		if(n!=m||(s1&1)||(s2&1)){puts("No");continue;}
		f[0].reset(),f[0][0]=1;For(i,1,n)
			f[i]=f[i-1]|(f[i-1]<<l[i]);
		now=s1>>1;Rof(i,n,1)
			if(now>=l[i]&&f[i-1][now-l[i]])now-=l[i],l[i]=-l[i];
		if(now){puts("No");continue;}
		f[0].reset(),f[0][0]=1;For(i,1,n)
			f[i]=f[i-1]|(f[i-1]<<p[i]);
		now=s2>>1;Rof(i,n,1)
			if(now>=p[i]&&f[i-1][now-p[i]])now-=p[i],p[i]=-p[i];
		if(now){puts("No");continue;}
		puts("Yes");
		sort(l+1,l+1+n),sort(p+1,p+1+n); 
		For(i,1,n)a[i]=Point(l[i],p[i]);sort(a+1,a+1+n,cmp);
		int x=0,y=0;For(i,1,n){
			x+=a[i].x,printf("%d %d\n",x,y);
			y+=a[i].y,printf("%d %d\n",x,y);
		}
	}
	return 0;
}//dsadasdsa