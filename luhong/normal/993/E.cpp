#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1);
struct cp{double x,y;}a[530000],b[530000];
cp CP(double x,double y){cp o;o.x=x;o.y=y;return o;}
cp operator +(cp a,cp b){return CP(a.x+b.x,a.y+b.y);}
cp operator -(cp a,cp b){return CP(a.x-b.x,a.y-b.y);}
cp operator *(cp a,cp b){return CP(a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y);}
int cnt[201000],sum[201000],v[201000],id[201000];
void FFT(cp *a,int lim,int type)
{
	for(int i=0;i<lim;i++)if(i<id[i])swap(a[i],a[id[i]]);
	for(int len=2;len<=lim;len<<=1)
	{
		int mid=len>>1;
		cp w=CP(cos(2*PI/len),type*sin(2*PI/len));
		for(int l=0;l<lim;l+=len)
		{
			cp w0=CP(1,0);
			for(int i=0;i<mid;i++,w0=w0*w)
			{
				int t1=i+l,t2=i+mid+l;
				cp x=a[t1],y=w0*a[t2];
				a[t1]=x+y;a[t2]=x-y;
			}
		}
	}
}
int main()
{
	int n,x;scanf("%d%d",&n,&x);
	int S=0;long long ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);if(v[i]-x<0)v[i]=1;else v[i]=0;
		if(v[i]==0)S++;
		else {ans+=(1ll*S*S-S)/2+S;S=0;}
	}
	ans+=(1ll*S*S-S)/2+S;
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+v[i];cnt[sum[i]]++;}
	for(int i=0;i<=n;i++)a[i]=CP(cnt[n-i],0);
	cnt[0]++;cnt[sum[n]]--;
	for(int i=0;i<=n;i++)b[i]=CP(cnt[i],0);
	int lim=1,wz=0;while(lim<=n+n)lim<<=1,wz++;
	for(int i=0;i<lim;i++)id[i]=(id[i>>1]>>1)|((i&1)<<(wz-1));
	FFT(a,lim,1);FFT(b,lim,1);for(int i=0;i<lim;i++)a[i]=a[i]*b[i];FFT(a,lim,-1);
	printf("%lld ",ans);
	for(int i=1;i<=n;i++)printf("%lld ",(long long)(a[n-i].x/lim+0.5));
	return 0;
}
//a[i]-=xk
//a[i]<0?a[i]=1:a[i]=0;  k
// ans[sum[j]-sum[i-1]]++
//sum[i]sum[i-1] 
//ans[k]+=cnt1[i]*cnt2[i-k] FFT