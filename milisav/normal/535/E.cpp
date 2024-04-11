#include <algorithm>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct compet
{
	double x,y; //x,y
	int ind;
};
int n;
int s[300000];
int r[300000];
double si[300000];
double ri[300000];
double epsilon= 0.000000000000000000000000000000001;
int mins,minr;
int orijent(compet a,compet b,compet c)
{
	double d=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	//if(b.x-a.x<epsilon && a.x-b.x<epsilon && b.y-a.y<epsilon && a.y-b.y<epsilon) return -11;
	if(d-0<epsilon && 0-d<epsilon)
	{
		double db,dc;
		db=(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
		dc=(c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y);
		if(dc-db>epsilon) return 1;
		if(db-dc>epsilon) return -1;
		return 0;
	}
	if(d>epsilon) return 1;
	else return -1;
}
compet a[300000];
bool v[300000];
bool operator <(compet b,compet c)
{
	return orijent(a[0],b,c)>0;
}
stack<int> b;
int next_to_top()
{
	int pom,p;
	pom=b.top();
	b.pop();
	p=b.top();
	b.push(pom);
	return p;
}
int graham()
{
	/*for(int i=0;i<n;i++)
	{
		if(a[i].x-a[0].x<epsilon && a[0].x-a[i].x<epsilon && a[i].y-a[0].y<epsilon && a[0].y-a[i].y<epsilon)
		{
			v[a[i].ind]=true;
		}
		//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].ind<<endl;
	}*/
	v[a[0].ind]=true;
	b.push(0);
	b.push(1);
	b.push(2);
	for(int i=3;i<n;i++)
	{
		while(b.size()>=2 && orijent(a[next_to_top()],a[b.top()],a[i])<=0) b.pop();
		b.push(i);
	}
	//bool b1,b2;
	double xp=a[0].x;
	double yp=a[0].y;
	int ip=a[0].ind;
	v[ip]=true;
	while(b.size()>0)
	{
		//cout<<xp<<"   "<<yp<<endl;
		//cout<<a[b.top()].x<<" "<<a[b.top()].y<<endl;
		
		if(xp-a[b.top()].x>epsilon || (a[b.top()].x-xp<epsilon && yp-a[b.top()].y<epsilon && a[b.top()].y-yp<epsilon))
		{
			xp=a[b.top()].x;
			yp=a[b.top()].y;
			v[a[b.top()].ind]=true;
			b.pop();
		}
		else break;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//cin>>si[i]>>ri[i];
		//scanf("%lld %lld",&si[i],&ri[i]);
		scanf("%d %d",&s[i],&r[i]);
		si[i]=s[i];
		si[i]=1/si[i];
		ri[i]=r[i];
		ri[i]=1/ri[i];
		a[i].x=si[i];
		a[i].y=ri[i];
		a[i].ind=i;
	}
	if(n==1)
	{
		printf("1");
		return 0;
	}
	if(n==2)
	{
		if(s[0]>s[1] || r[0]>r[1])
		{
			printf("1 ");
		}
		if(s[1]>s[0] || r[1]>r[0])
		{
			printf("2 ");
		}
		if(s[0]==s[1] && r[0]==r[1])
		{
			printf("1 2");
			return 0;
		}
		return 0;
	}
	int ind=0;
	//mins = minr = 0;
	compet pom;
	for(int i=1;i<n;i++)
	{
		if(a[ind].y-a[i].y>epsilon || (a[ind].y-a[i].y<epsilon && a[i].y-a[ind].y<epsilon && a[ind].x-a[i].x>epsilon)) ind=i;
	}
	//cout<<ind<<" "<<a[ind].x<<" "<<a[ind].y<<endl;
	pom=a[0];
	a[0]=a[ind];
	v[ind]=true;
	a[ind]=pom;
	sort(a+1,a+n);
	/*for(int i=0;i<n;i++)
	{
		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].ind<<endl;
	}*/
	graham();
	for(int i=1;i<n;i++)
	{
		if(v[a[i-1].ind] && a[i].x-a[i-1].x<epsilon && a[i-1].x-a[i].x<epsilon && a[i].y-a[i-1].y<epsilon && a[i-1].y-a[i].y<epsilon)
		{
			v[a[i].ind]=true;
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		if(v[a[i+1].ind] && a[i].x-a[i+1].x<epsilon && a[i+1].x-a[i].x<epsilon && a[i].y-a[i+1].y<epsilon && a[i+1].y-a[i].y<epsilon)
		{
			v[a[i].ind]=true;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(v[i]) printf("%d ",i+1);
	}
	return 0;
}