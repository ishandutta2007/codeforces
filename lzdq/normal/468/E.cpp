#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<int> Poly;
typedef pair<Poly,Poly> prp;
const int MAXN=1e5+5,mod=1e9+7;
int n,k,a[55][3];
int ax[55],ay[55];
ll fac[MAXN];
int pre[55];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
Poly operator *(Poly a,Poly b){
	if(a.empty()||b.empty()) return Poly{};
	Poly c(a.size()+b.size()-1);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
	while(!c.empty()&&c.back()==0) c.pop_back();
	return c;
}
Poly operator *(int c,Poly a){
	a.push_back(0);
	for(int i=a.size()-1; i; i--)
		a[i]=1ll*a[i-1]*c%mod;
	a[0]=0;
	return a;
}
Poly operator +(Poly a,Poly b){
	if(a.size()<b.size()) swap(a,b);
	for(int i=0; i<b.size(); i++)
		a[i]=(a[i]+b[i])%mod;
	return a;
}
Poly mul={1};
Poly vec[55];
int r,tot,w[55][55];
int cnte,h[55],to[105],nx[105];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[55];
ll vis;
void Dfs1(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs1(v);
	}
	return ;
}
prp Dfs2(int u){
	prp f;
	if(vis&1ll<<u-1) f.second.push_back(1);
	else f.first.push_back(1);
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		prp g(Dfs2(v));
		f.second=f.second*(g.first+g.second)+f.first*((u<=r?w[u][v-r]:w[v][u-r])*g.first);
		f.first=f.first*(g.first+g.second);
	}
	return f;
}
int f[1<<18],g[1<<18];
int ans;
int main(){
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=1; i<=k; i++){
		for(int j=0; j<3; j++)
			scanf("%d",a[i]+j);
		a[i][2]--;
		if(a[i][2]<0) a[i][2]+=mod;
		a[i][2]%=mod;
		pre[i]=i;
	}
	for(int i=1; i<=k; i++)
		for(int j=1; j<i; j++)
			if(a[i][0]==a[j][0]||a[i][1]==a[j][1])
				pre[fnd(i)]=fnd(j);
	for(int i=1; i<=k; i++)
		vec[fnd(i)].push_back(i);
	for(int _=1; _<=k; _++)
		if(!vec[_].empty()){
			*ax=*ay=0;
			for(int i:vec[_]){
				ax[++*ax]=a[i][0];
				ay[++*ay]=a[i][1];
			}
			sort(ax+1,ax+*ax+1);
			*ax=unique(ax+1,ax+*ax+1)-ax-1;
			sort(ay+1,ay+*ay+1);
			*ay=unique(ay+1,ay+*ay+1)-ay-1;
			if(*ax>*ay){
				swap(ax,ay);
				for(int j:vec[_])
					swap(a[j][0],a[j][1]);
			}
			r=*ax,tot=*ax+*ay;
			for(int i=1; i<=*ax; i++)
				for(int j=1; j<=*ay; j++)
					w[i][j]=0;
			for(int i:vec[_]){
				int x=lower_bound(ax+1,ax+*ax+1,a[i][0])-ax,y=lower_bound(ay+1,ay+*ay+1,a[i][1])-ay;
				w[x][y]=a[i][2];
				a[i][0]=x;
				a[i][1]=y;
			}
			if(*ax+*ax+*ay<vec[_].size()){
				memset(f,0,sizeof(int)<<r);
				f[0]=1;
				for(int i=1; i<=*ay; i++){
					memcpy(g,f,sizeof(int)<<r);
					for(int j=1; j<=r; j++)
						if(w[j][i])
							for(int k=0; k<1<<r; k++)
								if(!(1<<j-1&k))
									g[1<<j-1|k]=(g[1<<j-1|k]+1ll*f[k]*w[j][i])%mod;
					memcpy(f,g,sizeof(int)<<r);
				}
				Poly res(r+1);
				for(int i=0; i<1<<r; i++)
					(res[__builtin_popcount(i)]+=f[i])%=mod;
				mul=mul*res;
			}else{
				cnte=0;
				for(int i=1; i<=tot; i++)
					pre[i]=i,h[i]=0;
				Poly eu,ev;
				for(int i:vec[_]){
					int x=a[i][0],y=a[i][1];
					if(fnd(x)==fnd(y+r)) eu.push_back(x),ev.push_back(y);
					else pre[fnd(x)]=fnd(y+r),adde(x,y+r),adde(y+r,x);
				}
				Dfs1(1);
				int m=eu.size();
				Poly res(r+1);
				for(int k=0; k<1<<m; k++){
					vis=0;
					int cnt=0,co=1;
					for(int i=0; i<m; i++)
						if(1<<i&k){
							ll t=1ll<<eu[i]-1|1ll<<ev[i]+r-1;
							if(t&vis){
								vis=-1;
								break;
							}
							vis|=t;
							cnt++;
							co=1ll*co*w[eu[i]][ev[i]]%mod;
						}
					if(vis==-1) continue;
					prp s(Dfs2(1));
					Poly t(s.first+s.second);
					for(int i=0; i<t.size(); i++)
						res[i+cnt]=(res[i+cnt]+1ll*co*t[i])%mod;
				}
				mul=mul*res;
			}
		}
	for(int i=0; i<mul.size(); i++)
		ans=(ans+mul[i]*fac[n-i])%mod;
	printf("%d\n",ans);
	return 0;
}