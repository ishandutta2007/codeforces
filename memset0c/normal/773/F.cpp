#include<bits/stdc++.h>
#define twice(f) {int _=0;f;_=1;f;}
typedef long long i64;
typedef __int128 i128;
const int N=3e4+10,L=32;
const i64 mod=4179340454199820289;
int n,m,p,l,lim,len[L],rev[N<<2];
i64 invlim,w[N<<2];
struct z{
	int x;
	z(int x=0):x(x){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%p;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+p:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=p?a.x-p:a.x;}
}ans,tmp[2][N],f[L][2][N];
inline z fpow(z a,int b){z s=1;for(;b;b>>=1,a=a*a)if(b&1)s=s*a;return s;}
inline i64 fpow(i64 a,i64 b){i64 s=1;for(;b;b>>=1,a=(i128)a*a%mod)if(b&1)s=(i128)s*a%mod;return s;}
void init(int n){
	int k=0; lim=1; while(lim<=(n<<1))lim<<=1,++k;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int len=1;len<lim;len<<=1){
		i64 wn=fpow(3ll,(mod-1)/(len<<1)); w[len]=1;
		for(int i=1;i<len;i++)w[i+len]=(i128)w[i+len-1]*wn%mod;
	}
	invlim=fpow((i64)lim,(mod-2));
}
void dft(i64 *a){
	for(int i=0;i<lim;i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int len=1;len<lim;len<<=1)
		for(int i=0;i<lim;i+=(len<<1))
			for(int j=0;j<len;j++){
				i64 x=a[i+j],y=(i128)a[i+j+len]*w[j+len]%mod;
				a[i+j]=x+y; if(a[i+j]>=mod)a[i+j]-=mod;
				a[i+j+len]=x-y; if(a[i+j+len]<0)a[i+j+len]+=mod;
			}
}
void multi(z *f,z *g,z *h){
	static i64 a[N<<2],b[N<<2];
	memset(a+n+1,0,(lim-n-1)<<3),memset(b+n+1,0,(lim-n-1)<<3);
	for(int i=0;i<=n;i++)a[i]=f[i].x,b[i]=g[i].x;
	// printf("  "); for(int i=0;i<lim;i++)printf("%lld%c",a[i]," \n"[i+1==lim]);
	// printf("* "); for(int i=0;i<lim;i++)printf("%lld%c",b[i]," \n"[i+1==lim]);
	dft(a),dft(b);
	for(int i=0;i<lim;i++)a[i]=(i128)a[i]*b[i]%mod;
	dft(a),std::reverse(a+1,a+lim);
	for(int i=0;i<lim;i++)a[i]=(i128)invlim*a[i]%mod;
	// printf("= "); for(int i=0;i<lim;i++)printf("%lld%c",a[i]," \n"[i+1==lim]);
	for(int i=0;i<=n;i++)h[i]=h[i]+z(a[i]%p);
}
void transformX2(z s[2][N],z t[2][N],int len){
	static z f[N];
	for(int i=0;i<=n;i++)f[i]=s[0][i]+s[1][i];
	twice(for(int i=0;i<=n;i++)t[_][i]=s[_][i]+s[_^(len&1)][i]);
	twice(multi(f,s[_],t[_^(len&1)]));
}
void transformP1(z s[2][N],z t[2][N],int len){
	twice(memcpy(t[_],s[_],(n+1)<<2));
	t[len&1][1]=t[len&1][1]+1;
	for(int i=1;i<=n;i++)t[len&1][i]=t[len&1][i]+s[0][i-1]+s[1][i-1];
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&p);
	init(n+1);
	while(m>>(l+1))++l;
	for(int k=1;k<=l;k++)len[k]=m>>k;
	// for(int k=1;k<=l;k++)printf("%d len=%d\n",k,len[k]);
	for(int k=l;k>=1;k--){
		if(len[k]==1){
			f[k][1][1]=1;
		}else{
			if(len[k]-(len[k+1]<<1)){
				twice(memset(tmp[_],0,(n+1)<<2));
				transformX2(f[k+1],tmp,len[k+1]);
				// twice(for(int i=0;i<=n;i++)printf("%d%c",tmp[_][i]," \n"[i==n]));
				transformP1(tmp,f[k],len[k]);
			}else{
				transformX2(f[k+1],f[k],len[k+1]);
			}
		}
		// twice(
		// 	printf("%d[%d] >> ",k,_);
		// 	for(int i=0;i<=n;i++)printf("%d%c",f[k][_][i]," \n"[i==n]);
		// );
	}
	for(int k=1;k<=l;k++)
		for(int i=1;i<=n;i+=2)
			ans=ans+f[k][1][i];
	printf("%d\n",ans.x);
}
/*
0 5 25 70 130 166 148
0 5 20 50 80 86 62
0 2 4 3 1 0 0
0 3 6 7 4 1 0
0 1 1 0 0 0 0
0 1 0 0 0 0 0
0 0
0 1
*/