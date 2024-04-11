#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=15005;
int n,a[MAXN];
int len;
struct BIT1{
	int mi[MAXN];
	inline void Init(){
		memset(mi,0x3f,sizeof(mi));
	}
	inline int query(int x){
		int res=MAXN;
		for(int i=x; i<=n; i+=i&-i)
			res=min(res,mi[i]);
		return res;
	}
	inline void add(int x,int y){
		for(int i=x; i; i&=i-1)
			mi[i]=min(mi[i],y);
	}
}A;
struct BIT2{
	int mx[MAXN];
	inline void Init(){
		memset(mx,0,sizeof(mx));
	}
	inline int query(int x){
		int res=0;
		for(int i=x; i; i&=i-1)
			res=max(res,mx[i]);
		return res;
	}
	inline void add(int x,int y){
		for(int i=x; i<=n; i+=i&-i)
			mx[i]=max(mx[i],y);
	}
}B;
int f[MAXN][2],g[MAXN][2];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		reverse(a+1,a+n+1);
		for(int i=2; i<=n; i++)
			f[i][0]=MAXN,f[i][1]=0;
		f[1][0]=f[1][1]=a[1];
		bool ok=1;
		len=0;
		while(ok){
			A.Init();
			B.Init();
			ok=0;
			len++;
			for(int i=1; i<=n; i++){
				if(i>len){
					B.add(f[i-len][0],a[i-len]);
					A.add(f[i-len][1],a[i-len]);
				}
				g[i][0]=A.query(a[i]);
				g[i][1]=B.query(a[i]);
				if(g[i][0]<=n||g[i][1]>0) ok=1;
				A.add(a[i],f[i][0]);
				B.add(a[i],f[i][1]);
			}
			memcpy(f,g,sizeof(f));
		}
		ans=len;
		for(int i=2; i<=n; i++)
			f[i][0]=f[i][1]=a[i];
		f[1][0]=MAXN;
		f[1][1]=0;
		len=1;
		ok=1;
		while(ok){
			A.Init();
			B.Init();
			ok=0;
			len++;
			for(int i=1; i<=n; i++){
				if(i>len){
					B.add(f[i-len][0],a[i-len]);
					A.add(f[i-len][1],a[i-len]);
				}
				g[i][0]=A.query(a[i]);
				g[i][1]=B.query(a[i]);
				if(g[i][0]<=n||g[i][1]>0) ok=1;
				A.add(a[i],f[i][0]);
				B.add(a[i],f[i][1]);
			}
			memcpy(f,g,sizeof(f));
		}
		ans=max(ans,len-1);
		printf("%d\n",ans);
	}
	return 0;
}