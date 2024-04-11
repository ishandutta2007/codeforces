#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct st
{
	int d;
	int b;
	int k;
};
//262144
long long int x[524300];
int a[524300];
int b[524300];
int h[524300];
int c[200000];
int d[200000];
st f[200000];
bool operator <(st i, st j)
{
	return i.d<j.d || (i.d==j.d && i.k<j.k) || (i.d==j.d && i.k==j.k && i.k==0 && a[i.b]<a[j.b]);
}
int n;
inline long long int maxim(int i,int l,int r)
{
	/*if(l-262144==1 && r-262144==2)
	{
		cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<x[i]<<endl;
	}*/
	if(l>b[i]) return 0;
	if(r<a[i]) return 0;
	if(a[i]>=l && b[i]<=r) return x[i];
	long long int u,v;
	u=maxim(i*2+1,l,r);
	v=maxim(i*2+2,l,r);
	if(u>v) return u;
	else return v;
}
int main()
{
	st pom;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&h[i]);
		f[i].b=i;
		f[i].d=a[i];
		f[i].k=1;
		f[i+n].b=i;
		f[i+n].d=b[i];
		f[i+n].k=0;
		d[i]=-1;
	}
	sort(f,f+2*n);
	for(int i=0;i<2*n;i++)
	{
		if(d[f[i].b]==-1) 
		{
			d[f[i].b]=i;
			x[i+262144]=0;
		}
		else
		{
			//cout<<d[f[i].b]<<" "<<i<<endl;
			x[i+262144]=h[f[i].b];
			c[i]=d[f[i].b]+262144;
			c[d[f[i].b]]=i+262144;
		}
		//cout<<"x["<<i<<"]="<<x[i+262144]<<" ";
	}
	/*for(int i=3;i<=6;i++)
	{
		a[i]=i;
		b[i]=i;
	}
	int wtf;
	for(int i=2;i>=0;i--)
	{
		a[i]=a[i*2+1];
		b[i]=b[i*2+2];
		cout<<a[i]<<" "<<b[i]<<endl;
		//if(i==0 || i==1 || i==2 || i==4)cout<<a[i]<<" "<<b[i]<<endl;
		//cin>>wtf;
		//x[i]=x[i*2+1];
		//if(x[i*2+2]>x[i]) x[i]=x[i*2+2];
	}*/
	for(int i=262145;i<=524286;i++)
	{
		a[i]=i;
		b[i]=i;
	}
	int wtf;
	for(int i=262144;i>=0;i--)
	{
		a[i]=a[i*2+1];
		b[i]=b[i*2+2];
		x[i]=x[i*2+1];
		if(x[i*2+2]>x[i]) x[i]=x[i*2+2];
	}
	int j;
	long long int l=-1;
	for(int i=262144;i<=524288;i++)
	{
		if(x[i]>0)
		{
			if(x[i]>l) l=x[i];
			//	cout<<c[i-262144]-262144<<" "<<i-1-262144<<endl;
			x[i]=x[i]+maxim(0,c[i-262144],i-1);
			//cout<<x[i]<<endl;
			j=i;
			if(x[i]>l) l=x[i];
			while(j>0)
			{
				j=(j-1)/2;
				x[j]=x[j*2+1];
				if(x[j*2+2]>x[j]) x[j]=x[j*2+2];
			}
			/*for(int q=0;q<2*n;q++)
			{
				cout<<"x["<<q<<"]="<<x[q+262144]<<" ";
			}*/
		}
		
	}
	printf("%lld",l);
	return 0;
}