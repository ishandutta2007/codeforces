#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 100005

int n,q,sn[N],nx[N<<1],ed[N<<1],val[N<<1],x,y,z,d[N],deg[N],las,*aim[N],len;

inline bool cmp(const int *a,const int *b){return *a>*b;}

struct tree{
	int s,d[N],bot[N],top[N],f[N][20],h[N],v[N][20],sum,ans[N],fval[N],de[N],dp[N];
	
	void getfa(int x,int fa){
		*f[x]=fa;
		for(int j=sn[x];j;j=nx[j]) if(ed[j]^fa){
			getfa(ed[j],x);
			fval[ed[j]]=val[j];
		}
	}
	
	void build(){
		getfa(s,0);
		len=0;
		rep(i,1,n) if(deg[i]==1 && i!=s) aim[++len]=d+i;
		sort(aim+1,aim+1+len,cmp);
		rep(i,1,len){
			int j=aim[i]-d,k=j;
			while(!bot[k] && k) bot[k]=j,h[j]+=fval[k],k=*f[k];
		}
		len=0;
		rep(i,1,n) if(deg[i]==1 && i!=s) aim[++len]=h+i,++sum;
		sort(aim+1,aim+1+len,cmp);
		rep(i,1,len){
			int j=aim[i]-h,k=j;
			while(!*v[k] && k) *v[k]=i,k=*f[k];
			ans[i]=ans[i-1]+h[j];
			de[i]=h[j];
			dp[i]=bot[j];
		}
		rep(j,1,17) rep(i,1,n){
			f[i][j]=f[f[i][j-1]][j-1];
			v[i][j]=min(v[i][j-1],v[f[i][j-1]][j-1]);
		}
	}
	
	int work(int x,int y){
		if(2*y-1>sum) return ans[len];
		if(*v[x]<=2*y-1) return ans[2*y-1];
		int tot=ans[2*y-1]+d[bot[x]];
		dep(i,17,0) if(v[x][i]>2*y-1) x=f[x][i];
		tot-=d[x]+min(d[bot[x]]-d[x],dp[2*y-1]!=bot[x]?de[2*y-1]:d[bot[x]]-d[x]);
		return tot;
	}
	
}A,B;

void getdpt(int x,int fa,int dpt,int *d){
	d[x]=dpt;
	for(int j=sn[x];j;j=nx[j])
		if(ed[j]^fa)
			getdpt(ed[j],x,dpt+val[j],d);
}

int main(){
	scanf("%d%d",&n,&q);
	rep(i,2,n){
		scanf("%d%d%d",&x,&y,&z);
		nx[i]=sn[x],sn[x]=i,ed[i]=y,val[i]=z;
		nx[i+n]=sn[y],sn[y]=i+n,ed[i+n]=x,val[i+n]=z;
		deg[x]++,deg[y]++;
	}
	getdpt(1,0,0,d);
	A.s=max_element(d+1,d+1+n)-d;
	getdpt(A.s,0,0,A.d);
	B.s=max_element(A.d+1,A.d+1+n)-A.d;
	getdpt(B.s,0,0,B.d);
	A.build(),B.build();
	
	while(q--){
		scanf("%d%d",&x,&y);
		x=(x+las-1)%n+1;
		y=(y+las-1)%n+1;
		printf("%d\n",las=max(A.work(x,y),B.work(x,y)));
	}
}