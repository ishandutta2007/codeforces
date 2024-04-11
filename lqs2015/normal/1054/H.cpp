#include<bits/stdc++.h>
using namespace std;
const long double pi=acos(-1);
const int mod=490019;
int n,m,sz,rev[1111111],cnt,c,a[111111],b[111111],ans,aa[1111111],bb[1111111];
long long cur;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
struct cmplx
{
	double a,b;
	cmplx()
	{
		a=b=0.00;
	}
	cmplx operator + (const cmplx &u) const
	{
		cmplx res;
		res.a=a+u.a;res.b=b+u.b;
		return res;
	}
	cmplx operator - (const cmplx &u) const
	{
		cmplx res;
		res.a=a-u.a;res.b=b-u.b;
		return res;
	}
	cmplx operator * (const cmplx &u) const
	{
		cmplx res;
		res.a=a*u.a-b*u.b;res.b=a*u.b+u.a*b;
		return res;
	}
	cmplx operator / (const double u) const
	{
		cmplx res;
		res.a/=u;res.b/=u;
		return res;
	}
};
int s[1111111],t[1111111];
struct MTT
{
	int rev[1111111],sz,cnt,to,p,fu,cur;
	cmplx a[1111111],b[1111111],c[1111111],d[1111111],C[1111111],D[1111111];
	cmplx x,y,ws[1111111];
	long long aa[1111111],bb[1111111],cc[1111111],dd[1111111],res[1111111]; 
	void fft(cmplx c[],int flag)
	{
		for (int i=0;i<sz;i++)
		{
			if (rev[i]>i) swap(c[i],c[rev[i]]);
		}
		for (int i=2;i<=sz;i<<=1)
		{
			for (int j=0;j<sz;j+=i)
			{
				fu=-flag*sz/i;
				for (int k=j;k<j+i/2;k++)
				{
					cur=fu*(k-j);
					if (cur<0) cur+=sz;
					cmplx tmp1=c[k];
					cmplx tmp2=c[k+i/2]*ws[cur];
					c[k]=tmp1+tmp2;
					c[k+i/2]=tmp1-tmp2;
				}
			}
		}
		if (flag==-1)
		{
			for (int i=0;i<sz;i++)
			{
				c[i].a/=(double)sz;
				c[i].b/=(double)sz;
			}
		}	
	}
	void mul(int s[],int t[],int n,int m)
		{
			sz=1;
			cnt=0;
			while(sz<n+m)
			{
				sz*=2;
				cnt++;
			}
			rev[0]=0;
			for (int i=1;i<sz;i++)
			{
				rev[i]=(rev[i>>1]>>1)|((i&1)<<(cnt-1));
			}
			for (int i=0;i<sz;i++) 
			{
				ws[i].a=cos(2.00*pi/(double)sz*(double)i);
				ws[i].b=sin(2.00*pi/(double)sz*(double)i);
			}
			for (int i=0;i<sz;i++)
			{
				a[i].b=(double)(s[i]>>15);a[i].a=(double)(s[i]&32767);
				b[i].b=(double)(t[i]>>15);b[i].a=(double)(t[i]&32767);
			}
			fft(a,1);fft(b,1);
			for (int i=0;i<sz;i++)
			{
				to=sz-i;
				if (to==sz) to=0;
				x=b[i]+b[to];y=b[i]-b[to];
				c[i].a=x.b/2.00;c[i].b=-y.a/2.00;
				c[to].a=x.b/2.00;c[to].b=y.a/2.00;
				d[i].a=x.a/2.00;d[i].b=y.b/2.00;
				d[to].a=x.a/2.00;d[to].b=-y.b/2.00;
			} 
			for (int i=0;i<sz;i++)
			{
				C[i]=a[i]*c[i];
				D[i]=a[i]*d[i];
			}
			fft(C,-1);fft(D,-1);
			for (int i=0;i<sz;i++)
			{
				aa[i]=(long long)(C[i].a+0.50);
				bb[i]=(long long)(C[i].b+0.50);
				cc[i]=(long long)(D[i].a+0.50);
				dd[i]=(long long)(D[i].b+0.50);
				aa[i]%=p;bb[i]%=p;cc[i]%=p;dd[i]%=p;
			}
			for (int i=0;i<sz;i++)
			{
				res[i]=((aa[i]<<15ll)+(bb[i]<<30ll)+cc[i]+(dd[i]<<15))%p;
			}
		}
}mtt; 
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	sz=1;
	while(sz<mod)
	{
		sz<<=1;
		cnt++;
	}
	for (int i=0;i<n;i++)
	{
		int ii=1ll*i*i%(mod-1);
		aa[ii]=(1ll*a[i]*binpow(c,(mod-1)-(1ll*(ii-1)*ii/2)%(mod-1))+aa[ii])%mod;
	}
	for (int i=0;i<m;i++)
	{
		int ii=1ll*i*i%(mod-1)*i%(mod-1);
		bb[ii]=(1ll*b[i]*binpow(c,(mod-1)-(1ll*(ii-1)*ii/2)%(mod-1))+bb[ii])%mod;
	}
	mtt.p=mod;
	mtt.mul(aa,bb,sz,sz);
	for (int i=0;i<mtt.sz;i++)
	{
		cur=mtt.res[i]%mod;
		ans=(1ll*cur*binpow(c,(1ll*i*(i-1)/2)%(mod-1))+ans)%mod;		
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}