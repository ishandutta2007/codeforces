#include<bits/stdc++.h>
#define int long long
#define ull long long
const int N=600050,P=21,base=1313131,mod=998244353;
using namespace std;


char gc(){
	static char s[base],*p1=s,*p2=s+base;
	if(p1==p2)p1=s,p2=s+fread(s,1,base,stdin);
	return p2==s?EOF:*p1++;
}
int read(){
	int x=0;char c=gc(),f=1;
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=gc();}
	while(c<='9'&&c>='0') x=x*10+c-'0',c=gc();
	return f*x;
} 

void pc(char c){
	static char s[base],*p1=s,*p2=s+base;
	if(c==-1) fwrite(s,1,p1-s,stdout);
	if(p1==p2) fwrite(s,1,base,stdout),p1=s;
	*p1++=c;
}
void print(int x)
{
	static char s[20],t;
	if(x<0) pc('-'),x=-x;
	if(!x) pc('0');
	while(x) s[++t]=x%10,x/=10;
	while(t) pc(s[t--]+'0');
}

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

ull gsc(ull x,ull y){
    ull ans=1;
    for(ull i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}ull inv(ull k){return gsc(k,mod-2);}
const ull ibase=inv(base);

int n,q;
int fa[N][P],dp[N];
ull up[N],dn[N],pw[N],ln[N],iv[N];
int len[N],sn[N];
int top[N]; 
int cnt,id[N],bel[N];
int ora[N],co,in[N];
int mn[P][N];
vector<int> cu[N],cd[N];
string s;

int dmn(int x,int y){
	return dp[x]<dp[y]?x:y;
}

int lca(int x,int y){
	x=in[x],y=in[y];
	if(x>y)swap(x,y); 
	int z=ln[y-x+1];
	return dmn(mn[z][x],mn[z][y-(1<<z)+1]);
}

int getf(int k,int p){
	if(p==0)return k;
	int z=ln[p];p-=1<<z;
	k=fa[k][z];
	if(p==0)return k;
	p-=dp[k]-dp[top[k]];
	return p>=0?cu[bel[k]][p]:cd[bel[k]][-p];
}

void dfs(int k,int f){
	ora[++co]=k;
	in[k]=co;
	fa[k][0]=f;
	dp[k]=dp[f]+1;
	dn[k]=(dn[f]*base+s[k])%mod;
	up[k]=(s[k]*pw[dp[k]-1]+up[f])%mod;
	for(int i=1;i<P;i++)fa[k][i]=fa[fa[k][i-1]][i-1];
	fore(k)if(_to!=f){
		dfs(_to,k);
		ora[++co]=k;
		sn[k]=len[sn[k]]>len[_to]?sn[k]:_to;
	}
	len[k]=len[sn[k]]+1;
}

void df5(int k,int l){
	if(l==1){
		++cnt,top[k]=k;
		for(int i=0,o=k;i<len[k];i++)
			cu[cnt].push_back(o),o=fa[o][0];
		for(int i=0,o=k;i<len[k];i++)
			cd[cnt].push_back(o),o=sn[o];
	}
	id[k]=l,bel[k]=cnt;
	cu[cnt].push_back(k);
	if(sn[k])top[sn[k]]=top[k],df5(sn[k],l+1);
	fore(k)if(_to!=fa[k][0]&&_to!=sn[k])
		df5(_to,1);
}

void init(){
	pw[0]=iv[0]=1,ln[0]=-1;
	for(int i=1;i<=n<<1;i++)
		pw[i]=pw[i-1]*base%mod,iv[i]=iv[i-1]*ibase%mod,ln[i]=ln[i>>1]+1;
	dfs(1,0);
	df5(1,1);
	for(int i=1;i<=co;i++)
		mn[0][i]=ora[i];
	for(int i=1;i<P;i++)
		for(int j=1;j<=co-(1<<i)+1;j++)
			mn[i][j]=dmn(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
} 

ull ghs(int s,int t,int lc,int ln){
	if(dp[s]-dp[lc]+1>=ln){
		int f=getf(s,ln);
		return (up[s]-up[f]+mod)*iv[dp[f]]%mod;
	}
	else{
		int l=dp[s]-dp[lc],y=getf(t,dp[s]+dp[t]-2*dp[lc]-ln+1);
		ull u=((up[s]-up[lc]+mod)*iv[dp[lc]])%mod,d=(dn[y]-dn[fa[lc][0]]*pw[ln-l])%mod;
		return ((u*pw[ln-l]+d)%mod+mod)%mod;
	}
}

int calc(int a,int b,int c,int d){
	int la=lca(a,b),lc=lca(c,d);
	int lna=dp[a]+dp[b]-dp[la]*2+1,lnc=dp[c]+dp[d]-dp[lc]*2+1;
	int l=0,r=min(lna,lnc),ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(ghs(a,b,la,mid)==ghs(c,d,lc,mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

void solve(){
	cin>>n>>s,s='0'+s;
	for(int i=1;i<n;i++){
		int x,y;x=read(),y=read();
		add(x,y),add(y,x);
	}
	init();
	q=read();
	for(int i=1;i<=q;i++){
		int a,b,c,d;a=read(),b=read(),c=read(),d=read();
		print(calc(a,b,c,d)),pc('\n');
	}
	pc(-1);
}

main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}