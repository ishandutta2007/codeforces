#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],b[maxn],mx[maxn*4],l[maxn],r[maxn],id[maxn],g[maxn];
double p[maxn],f[5005][5005],res;
vector<int>e[maxn];
bool cmp(int x,int y){if(l[x]==l[y])return r[x]>r[y];return l[x]<l[y];}
void build(int rt,int l,int r){
	if(l==r){mx[rt]=a[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	mx[rt]=max(mx[ls],mx[rs]);
}
int query(int rt,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R){return mx[rt];}
	return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
void dfs(int x,int fa){
	//cout<<x<<endl;
	g[x]=query(1,1,n,l[x],r[x]);
	f[x][0]=1-p[x];//cout<<g[x]<<" "<<l[x]<<" "<<r[x]<<" "<<x<<endl;
	for(auto i:e[x])if(i^fa)
		dfs(i,x),f[x][0]*=f[i][min(m,g[x]-g[i])];
	for(int i=1;i<=m;i++){
        double s0=p[x],s1=1-p[x];
        for(auto j:e[x])
            s1*=f[j][min(m,i+g[x]-g[j])],
            s0*=f[j][min(m,i+g[x]-g[j])-1];
        f[x][i]=s0+s1;
        //cout<<f[x][i]<<" "<<i<<" "<<x<<endl;
    }
}
    
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++){
		l[i]=read(),r[i]=read();cin>>p[i];id[i]=i;
	}l[++m]=1,r[m]=n;p[m]=0;id[m]=m;//cout<<m<<endl;
	sort(id+1,id+m+1,cmp);
	for(int i=2;i<=m;i++)
		for(int j=i-1;j>=1;j--)if(l[id[i]]>=l[id[j]]&&r[id[i]]<=r[id[j]]){e[id[j]].pb(id[i]);break;}
	dfs(id[1],0);res=0;res=(g[id[1]])*f[id[1]][0];//cout<<res<<endl;
	for(int i=1;i<=m;i++)res+=(g[id[1]]+i)*(f[id[1]][i]-f[id[1]][i-1]);
	printf("%.8lf",res);
 	return 0;
}