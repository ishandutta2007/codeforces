#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1010;
const int INF=1000000000;

int n;
int x[MaxN],y[MaxN],tx[MaxN],ty[MaxN];
long double L,R;

long double det(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}

void line(long double x1,long double y1,long double x2,long double y2,long double y0,long double& x0)
{
	long double A=y1-y2;
	long double B=x2-x1;
	long double C=A*x1+B*y1;
	x0=(C-B*y0)/A;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	L=x[1],R=x[2];
	if (L>R)
	{
		for (int i=1,j=2;i<=n;++i)
		{
			tx[i]=x[j];
			ty[i]=-y[j];
			--j;
			if (!j) j=n;
		}
		for (int i=1;i<=n;++i)
		{
			x[i]=tx[i];
			y[i]=ty[i];
		}
		swap(L,R);
	}
	for (int i=3;i<=n;++i)
	{
		int px=x[1],py=y[1];
		for (int j=i+1;j<=n;++j)
			if (det(x[i],y[i],x[j],y[j],px,py)>0)
			{
				px=x[j];
				py=y[j];
			}
		long double tmp;
		line(x[i],y[i],px,py,y[1],tmp);
		L=max(L,tmp);
		px=x[2],py=y[2];
		for (int j=3;j<i;++j)
			if (det(x[i],y[i],px,py,x[j],y[j])>0)
			{
				px=x[j];
				py=y[j];
			}
		line(x[i],y[i],px,py,y[1],tmp);
		R=min(R,tmp);
	}
	int ans=0;
	for (int i=L-1;i<=R+1;++i)
		if (L<=i&&i<=R) ++ans;
	cout<<ans<<endl;
	return 0;
}