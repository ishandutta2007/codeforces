	//{{{
#include<bits/stdc++.h>
	using namespace std;typedef long long ll;
	template<typename T>inline void read(T &x)
	{
		x=0;char c=getchar(),bz=0;
		for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
		for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
		bz?x=-x:x;
	}/*}}}*/
const int N=5005,D=N-3;int n,at,bt,ct,T[N<<1];ll rs=0;
struct hng{int x1,x2,y;char operator<(hng b) const {return y<b.y;}}a[N];
struct shu{int y1,y2,x;char operator<(shu b) const {return y1<b.y1;}}b[N],c[N];
inline void clr(int x) {for(;x<=10005;x+=x&(-x)) if(T[x]) T[x]=0;else break;}
inline void add(int x,int w) {for(;x<=10005;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
int main()
{
	read(n);for(int i=1,x,y,z,w;i<=n;i++)
	{
		read(y),read(x),read(w),read(z),x+=D,y+=D,z+=D,w+=D;
		if(x==z) a[++at]=(hng){min(y,w),max(y,w),x};
		if(y==w) b[++bt]=(shu){min(x,z),max(x,z),y};
	}sort(a+1,a+at+1);
	//{for(int i=1;i<=at;i++) printf("%d~%d , %d\n",a[i].x1-D,a[i].x2-D,a[i].y-D);putchar('\n');}
	for(int i=1,it;i<=at;i++)
	{
		ct=0;for(int j=1;j<=bt;j++) if(b[j].y1<=a[i].y&&a[i].y<=b[j].y2)
			if(a[i].x1<=b[j].x&&b[j].x<=a[i].x2) c[++ct]=b[j];
		//for(int j=1;j<=ct;j++) printf("%d , %d~%d\n",c[j].x-D,c[j].y1-D,c[j].y2-D);
		sort(c+1,c+ct+1),it=1;for(int j=1;j<i;j++)
		{
			while(it<=ct&&c[it].y1<=a[j].y) add(c[it].x,1),it++;
			int v=qry(a[j].x2)-qry(a[j].x1-1);rs+=1ll*v*(v-1)/2;
			//printf("%d ~ %d : %d\n",j,i,v);
		}
		//printf("%lld\n",rs),putchar('\n');
		for(int j=1;j<=it;j++) clr(c[j].x);
	}
	return printf("%lld\n",rs),0;
}