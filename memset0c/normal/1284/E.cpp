#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=2e4+10;
int n,m,l[N],r[N],sum[N];
long long ans;
long long cross(int x1,int y1,int x2,int y2){
    return (long long)x1*y2-(long long)x2*y1;
}
struct node{
	int x,y,i;
	inline int locate()const{
		if(x>=0&&y>=0)return 0;
		if(x<=0&&y>=0)return 1;
		if(x<=0&&y<=0)return 2;
		if(x>=0&&y<=0)return 3;
	}
	inline bool operator<(const node &other)const{
		// return atan2(x,y)<atan2(other.x,other.y);
		if(locate()!=other.locate())return locate()<other.locate();
		return cross(x,y,other.x,other.y)>0;
	}
}a[N],b[N];
inline long long C3(int n){return (long long)n*(n-1)*(n-2)/6;}
inline long long C4(int n){return (long long)n*(n-1)*(n-2)*(n-3)/24;}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(a[i].x),read(a[i].y);
	for(int i=1;i<=n;i++){
		memset(l,0,sizeof(l)),memset(r,0,sizeof(r));
		m=0;
		for(int j=1;j<=n;j++)if(i!=j){
			b[++m]=(node){a[j].x-a[i].x,a[j].y-a[i].y,j};
			b[++m]=(node){a[i].x-a[j].x,a[i].y-a[j].y,-j};
		}
		std::sort(b+1,b+m+1);
		for(int i=1;i<=m;i++)b[i+m]=b[i];
		m<<=1;
		// for(int i=1;i<=m;i++)printf("> %d %d %d\n",b[i].x,b[i].y,b[i].i);
		for(int i=1;i<=m;i++)if(b[i].i>0){
			if(!l[b[i].i])l[b[i].i]=i;
		}else if(b[i].i<0){
			if(l[-b[i].i]&&!r[-b[i].i])r[-b[i].i]=i;
		}
		for(int i=1;i<=m;i++)sum[i]=sum[i-1]+(b[i].i>0);
		ans+=C4(n-1);
		// printf("%d >> %lld\n",i,ans);
		// for(int i=1;i<=n;i++)print(l[i]," \n"[i==n]);
		// for(int i=1;i<=n;i++)print(r[i]," \n"[i==n]);
		for(int j=1;j<=n;j++)if(i!=j)ans-=C3(sum[r[j]]-sum[l[j]]);
		// printf("%d >> %lld\n",i,ans);
	}
	print(ans,'\n');
}