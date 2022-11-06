#include<bits/stdc++.h>
#define re register
#define ui unsigned int
const double pi=3.14159265358979323846264338327950;
int x1[100100],x2[100100],qq[200100];
const int maxn=(1<<20)+1;
struct com
{
	double a,b;
	inline com operator +(const com&A){return(com){a+A.a,b+A.b};}
	inline void operator +=(const com&A){a+=A.a,b+=A.b;}
	inline com operator -(const com&A){return(com){a-A.a,b-A.b};}
	inline com operator *(const com&A){return(com){a*A.a-b*A.b,a*A.b+b*A.a};}
	inline com operator *(re const double &o) {return (com){a*o,b*o};}
	inline com operator /(const int&A){return(com){a/A,b/A};}
	inline com operator !(){return(com){a,-b};}
	inline bool operator !=(const com&A){return a!=A.a||b!=A.b;}
};
com w[maxn],T1[maxn];
int getlen(re int n){re int x=1;for(;x<n;x*=2);return x;}
bool cp[maxn<<1];
void init(re int len)
{
	cp[1]=1;
	for(re int i=2;i<len;i++)
	{
		cp[i]=(cp[i>>1]&(!(i&1)))||(cp[i>>2]&((i>>1)&1));
	}
}
void fft(com*a,re int len)
{
	re ui i1=0;
	re com x1,x2,x3;
	for(re ui i=0,j=0;i<len;i++)
	{
		if(i<j)std::swap(a[i],a[j]);
		for(ui k=len>>1;;k>>=1)if((j^=k)>=k)break;
	}w[0]=(com){1,0};
	if(len>=2)
	{
		for(re ui i=0;i<len;i+=2)if(cp[(len+i)>>1])x1=a[i+1],a[i+1]=a[i]-x1,a[i]+=x1;
	}
	if(len>=4)
	for(re ui i=0;i<len;i+=4)
		if(cp[(len+i)>>2])
		{
			x1=a[i+2];
			x2=a[i+3];
			x3=(com){-x1.b+x2.b,-x2.a+x1.a};x1+=x2;
			a[i+2]=a[i]-x1;a[i]+=x1;
			a[i+3]=a[i+1]-x3;a[i+1]+=x3;
		}
	w[1]=(com){0,1};w[2]=(com){-1,0};
	for(re ui i=8,i2=3;i<=len;i<<=1,i2++)
	{
		i1=i>>2;
		com s=(com){cos(pi/i1/2),sin(pi/i1/2)};
		for(re ui j=3*i1-2;j>0;j-=2)
			w[j]=w[j>>1];
		for(re ui j=1;j<3*i1;j+=2)
			w[j]=s*w[j-1];
		for(re ui j=0;j<len;j+=i)
		if(cp[(len+j)>>i2]){re com*aa=a+j,*aaa=aa+i1,*bb=aaa+i1,*cc=bb+i1;
			for(re int k=0;k<i1;k++)
			{
				x1=w[k]*bb[k];
				x2=w[k*3]*cc[k];
				x3=(com){-x1.b+x2.b,-x2.a+x1.a};
				cc[k]=aaa[k]-x3;
				aaa[k]+=x3;
				x1+=x2;
				bb[k]=aa[k]-x1;
				aa[k]+=x1;
			}
		}
	}
}
void DFT(ui *a,com *R1,int len) {
	for(re int i=0;i<len;++i) R1[i]=(com){(double)a[i<<1],(double)a[i<<1|1]};
	fft(R1,len);
}
void DFTMul(com *R1,com *S1,int len) {
	for(re int i=0;i<len;++i) {
		re int j=len-1&len-i;
		com tmp=(i&len>>1)?(com){1,0}-w[i^len>>1]:w[i]+(com){1,0};
		T1[j]=R1[i]*S1[i]-(R1[i]-!R1[j])*(S1[i]-!S1[j])*tmp*0.25;
	}
}
void IDFT(long long *__ans,int len) {
	fft(T1,len);
	for(re int i=0;i<len*2;++i) __ans[i]=(i&1)?(long long)(T1[i>>1].b/len+0.5):(long long)(T1[i>>1].a/len+0.5);
}
ui xx1[270100],xx2[270100];
com xr1[200101],xr2[200101];
long long ans[270100],res[270100];
void Mul(ui*x1,ui*x2,long long*__ans,int len)
{
	DFT(x1,xr1,len);
	DFT(x2,xr2,len);
	DFTMul(xr1,xr2,len);
	IDFT(__ans,len);
}
int main()
{
	init(131072);
	re int n,m,q,len=131072;
	scanf("%d%d%d",&n,&m,&q);
	for(re int i=1;i<=n;i++)scanf("%d",&x1[i]);
	for(re int i=1;i<=m;i++)scanf("%d",&x2[i]);
	for(re int i=1;i<=q;i++)scanf("%d",&qq[i]);
	for(re int i=1;i<n;i++)
	{
		xx1[std::min(x1[i],x1[i+1])]++;
	}
	for(re int i=1;i<m;i++)
	{
		xx2[std::min(x2[i],x2[i+1])]++;
	}
	Mul(xx1,xx2,res,len);
	for(re int i=0;i<len*2;i++)ans[i]+=2*res[i],res[i]=0;
	memset(xx2,0,sizeof(xx2));
	for(re int i=1;i<=m;i++)
	{
		xx2[x2[i]]++;
	}
	Mul(xx1,xx2,res,len);
	for(re int i=0;i<len*2;i++)ans[i]-=2*res[i],res[i]=0;
	memset(xx1,0,sizeof(xx1));
	for(re int i=1;i<=n;i++)
	{
		xx1[x1[i]]++;
	}
	Mul(xx1,xx2,res,len);
	for(re int i=0;i<len*2;i++)ans[i]+=2*res[i],res[i]=0;
	memset(xx2,0,sizeof(xx2));
	for(re int i=1;i<m;i++)
	{
		xx2[std::min(x2[i],x2[i+1])]++;
	}
	Mul(xx1,xx2,res,len);
	for(re int i=0;i<len*2;i++)ans[i]-=2*res[i],res[i]=0;
	re int mi=1<<30;
	for(re int i=1;i<=m;i++)
	{
		ans[x1[1]+x2[i]]--;
		if(n!=1)ans[x1[n]+x2[i]]--;
		mi=std::min(mi,x1[1]+x2[i]);
		mi=std::min(mi,x1[n]+x2[i]);
		if(i!=1)
		{
			ans[x1[1]+std::min(x2[i-1],x2[i])]++;
			if(n!=1)ans[x1[n]+std::min(x2[i-1],x2[i])]++;
		}
	}
	for(re int i=2;i<=n;i++)
	{
		if(i!=n)
		{
			ans[x1[i]+x2[1]]--;
			if(m!=1)ans[x1[i]+x2[m]]--;
		}
		mi=std::min(mi,x1[i]+x2[1]);
		mi=std::min(mi,x1[i]+x2[m]);
		ans[std::min(x1[i-1],x1[i])+x2[1]]++;
		if(m!=1)ans[std::min(x1[i-1],x1[i])+x2[m]]++;
	}
	if(n==1||m==1)
	{
		for(re int i=1;i<=m;i++)
		{
			ans[x1[1]+x2[i]]--;
			if(n!=1)ans[x1[n]+x2[i]]--;
			mi=std::min(mi,x1[1]+x2[i]);
			mi=std::min(mi,x1[n]+x2[i]);
			if(i!=1)
			{
				ans[x1[1]+std::min(x2[i-1],x2[i])]++;
				if(n!=1)ans[x1[n]+std::min(x2[i-1],x2[i])]++;
			}
		}
		for(re int i=2;i<=n;i++)
		{
			if(i!=n)
			{
				ans[x1[i]+x2[1]]--;
				if(m!=1)ans[x1[i]+x2[m]]--;
			}
			mi=std::min(mi,x1[i]+x2[1]);
			mi=std::min(mi,x1[i]+x2[m]);
			ans[std::min(x1[i-1],x1[i])+x2[1]]++;
			if(m!=1)ans[std::min(x1[i-1],x1[i])+x2[m]]++;
		}
		ans[x1[1]+x2[1]]++;
		if(m==1)ans[x1[n]+x2[1]]++;
		else ans[x1[1]+x2[m]]++;
	}
	for(re int i=len*2;i>=0;i--)ans[i]+=ans[i+1];
	assert(ans[0]==2);
	for(re int i=1;i<=q;i++)printf("%lld\n",ans[qq[i]]-1);
}