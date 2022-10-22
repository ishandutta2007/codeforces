#include <bits\stdc++.h>

using namespace std;
struct comp
{
	double x,y;
};
inline comp operator *(comp a,comp b)
{
	comp z;
	z.x=a.x*b.x-a.y*b.y;
	z.y=a.x*b.y+a.y*b.x;
	return z;
}
inline comp operator +(comp a,comp b)
{
	comp z;
	z.x=a.x+b.x;
	z.y=a.y+b.y;
	return z;
}
inline comp operator -(comp a,comp b)
{
	comp z;
	z.x=a.x-b.x;
	z.y=a.y-b.y;
	return z;
}
inline comp polarcomp(double r,double ang)
{
	comp z;
	//cout<<r<<" "<<ang<<" "<<cos(ang)<<" "<<sin(ang)<<endl;
	z.x=r*cos(ang);
	z.y=r*sin(ang);
	return z;
}
inline comp compinverse(comp w)
{
	comp z;
	z.x=(w.x)/(w.x*w.x+w.y*w.y);
	z.y=(-w.y)/(w.x*w.x+w.y*w.y);
	return z;
}
const int mm=2097152;
int sl;
const double dd=1/2097152;
double epsilon=1e-5;
int n,k;
double PI;
int a[1005];
bool d[5000005];
bool p[5000005];
comp pr[5000005];
comp u[5000005];
//comp v[5000005];
int reverse(int i,int m)
{
	int j=0;
	int l1=1;
	int l2=m>>1;
	while(l1<l2)
	{
		if((i&l1)>0) j+=l2;
		if((i&l2)>0) j+=l1;
		l1=l1<<1;
		l2=l2>>1;
	}
	if(l1==l2)
	{
		if((i&l1)) j+=l1;
	}
	return j;
}
inline void FFT(int m,bool nin)
{
	for(int i=0;i<m;i++)
	{
		int j=reverse(i,m);
		if(i<j) swap(pr[i],pr[j]);
	}
	comp x,y;
	comp w;
	comp d;
	d.x=1.0;
	d.y=0.0;
	for(int l=2;l<=m;l=l<<1)
	{
		w=polarcomp(1.0,2.0*PI/double(l));
		if(!nin) w=compinverse(w);
		for(int j=0;j<m;j=j+l)
		{
			d.x=1.0;
			d.y=0.0;
			for(int i=j;i<j+(l>>1);i++)
			{
				x=pr[i];
				y=pr[i+(l>>1)]*d;
				pr[i]=x+y;
				pr[i+(l>>1)]=x-y;
				d=d*w;
			}
		}
	}
}
void Multiply(bool nec)
{
	int m=0;
	for(int i=0;i<1000000;i++)
	{
		if((nec && d[i]) || p[i]) m=i;
	}
	m=m+10;
	double t=m;
	t=log(t)/log(2.0);
	m=t;
	m=pow(2,m+1);
	m=(m<<1);
	//m=(m<<1);
	//cout<<m<<endl;
	/*if(m>=2000000)
	{
		while(true)
		{
			m++;
		}
	}*/
	for(int i=0;i<m;i++)
	{
		pr[i].y=0.0;
		if(nec)
		{
			if(d[i]) pr[i].x=1.0;
			else pr[i].x=0.0;
		}
		else
		{
			if(p[i]) pr[i].x=1.0;
			else pr[i].x=0.0;
		}
	}
	FFT(m,true);
	for(int i=0;i<m;i++)
	{
		u[i].x=pr[i].x;
		u[i].y=pr[i].y;
		pr[i].y=0.0;
		if(p[i]) pr[i].x=1.0;
		else pr[i].x=0.0;
	}
	FFT(m,true);
	for(int i=0;i<m;i++) pr[i]=pr[i]*u[i];
	FFT(m,false);
	t=1/double(m);
	//t=1;
	for(int i=0;i<m;i++)
	{
		if(pr[i].x*t>epsilon)
		{
			if(nec) d[i]=true;
			else p[i]=true;
		}
		else
		{
			if(nec) d[i]=false;
			else p[i]=false;
		}
	}
}
void Solve()
{
	int l=1;
	for(int i=0;i<n;i++) p[a[i]]=true;
	bool e=true;
	while(l<=k)
	{
		if((k&l)>0)
		{
			if(!e) Multiply(true);
			else
			{
				for(int i=0;i<=mm;i++) d[i]=p[i];
				e=false;
			}
		}
		Multiply(false);
		l=(l<<1);
		/*cout<<l<<endl;
		for(int i=1;i<=1000000;i++) if(p[i]) printf("%d ",i);
		cout<<endl<<endl<<endl;
		
		cout<<(l>>1)<<endl;
		for(int i=1;i<=1000000;i++) if(d[i]) printf("%d ",i);
		cout<<endl<<endl<<endl;*/
	}
}
int main()
{
	PI=acos(-1);
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	Solve();
	for(int i=1;i<=1000000;i++) if(d[i]) printf("%d ",i);
	return 0;
}