#include<bits/stdc++.h>
#define re register
typedef double lb;
const lb eps=1e-9L;
struct pi
{
	lb x,y;
	pi operator+(const pi&A){return (pi){x+A.x,y+A.y};}
	pi operator-(const pi&A){return (pi){x-A.x,y-A.y};}
	lb operator*(const pi&A){return x*A.y-y*A.x;}
	pi operator*(re lb A){return (pi){x*A,y*A};}
	pi operator/(re lb A){return (pi){x/A,y/A};}
	lb dis(){return sqrtl(x*x+y*y);}
	pi rou(){return (pi){-y,x};}
}q2[610],f[610],nn,nn1,nn2,pp[610];
struct li
{
	pi x,y;lb r;
	pi operator*(li A)
	{
		re lb xx=(A.x-x)*(y-x),yy=(y-x)*(A.y-x);
		return (A.x*yy+A.y*xx)/(xx+yy);
	}
	void sr(){r=atan2l(y.y-x.y,y.x-x.x);}
	bool operator<(li A)
	{
		if(fabs(r-A.r)>eps)return r<A.r;
		return (y-x)*(A.y-x)<0;
	}
	bool operator==(const li&A){return x.x==A.x.x&&x.y==A.x.y&&y.x==A.y.x&&y.y==A.y.y;}
}q1[610],p[610],q[610],qw;
bool in[610];
bool hf(re int n)
{
	re int l=1,r=0;
	for(re int i=1;i<=n;i++)if(in[i]&&(l>r||fabs(p[i].r-q1[r].r)>eps))
	{
		while(l<r&&(p[i].y-p[i].x)*(q2[r]-p[i].x)<=eps)r--;
		while(l<r&&(p[i].y-p[i].x)*(q2[l+1]-p[i].x)<=eps)l++;
		q1[++r]=p[i];
		if(l<r)q2[r]=q1[r]*q1[r-1];
		//printf("*l*%Lf %Lf %Lf %Lf %d %d\n",p[i].x.x,p[i].x.y,p[i].y.x,p[i].y.y,l,r);
	}//puts("*************");
	while(l<r&&(q1[l].y-q1[l].x)*(q2[r]-q1[l].x)<=eps)r--;
	if(r-l<2)return 0;
	nn=q2[r];
	return 1;
}
int n,id[610],tt[610];
bool che(re lb x)
{
	memset(in,0,sizeof(in));
	pi xx;
	for(re int i=1;i<=n;i++)p[i]=(li){f[i],f[i%n+1]},p[i].sr(),q[i]=p[i];
	for(re int i=1;i<=n;i++)
	{
		xx=p[i].y-p[i].x;xx=xx/xx.dis()*x;
		xx=(pi){-xx.y,xx.x};
		p[i+n]=(li){p[i].y+xx,p[i].x+xx};
		p[i+n].sr();q[i+n]=p[i+n];
	}
	std::sort(p+1,p+2*n+1);
	for(re int i=1;i<=2*n;i++)
	{
		for(re int j=1;j<=2*n;j++)if(q[i]==p[j]){id[i]=j;break;}
	}
	for(re int i=1;i<=n;i++)in[id[i]]=1;
	re int r=1;in[id[n+1]]=1;
	for(re int i=1;i<=n;i++)
	{
		while(r<i+n-1)
		{
			r++;
			in[id[(r-1)%n+1+n]]=1;//printf("*k*%d %d\n",r,(r-1)%n+1+n);
			if(!hf(2*n)){in[id[(r-1)%n+1+n]]=0,r--;break;}
		}
		hf(2*n);tt[i]=r;pp[i]=nn;//printf("**%d %d\n",i,tt[i]);
		in[id[i+n]]=0;
	}
	for(re int i=1;i<=n;i++)pp[i+n]=pp[i],tt[i+n]=tt[i]+n;
	for(re int i=1;i<=n;i++)
	{
		if(tt[tt[i]+1]+1>=i+n)
		{
			nn1=pp[i];nn2=pp[tt[i]+1];
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%lf%lf",&f[i].x,&f[i].y);
	re lb l=0,r=1e5,mid;
	for(mid=(l+r)/2;l<r-eps;mid=(l+r)/2)
	{
		if(che(mid))r=mid;
		else l=mid;
	}
	che(l);
	printf("%.12lf\n%.12lf %.12lf\n%.12lf %.12lf\n",l,nn1.x,nn1.y,nn2.x,nn2.y);
}