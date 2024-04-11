#include<iostream>
#include<iomanip>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N,M,Q;
int X[1<<17],Y[1<<17],Z[1<<17];
struct P3{
	long double x,y,z;
	P3():x(0),y(0),z(0){}
	P3(int id):x(X[id]),y(Y[id]),z(Z[id]){}
	P3(long double x,long double y,long double z):x(x),y(y),z(z){}
	P3 operator+(const P3&p)const{return P3(x+p.x,y+p.y,z+p.z);}
	P3 operator-(const P3&p)const{return P3(x-p.x,y-p.y,z-p.z);}
	P3 operator*(const long double k)const{return P3(x*k,y*k,z*k);}
};
P3 mul(const P3&l,const P3&r)
{
	return P3(l.x*r.x,l.x*r.y+l.y*r.x,l.y*r.y);
}
long double val(const P3&a,const long double x)
{
	return a.x+a.y*x+a.z*x*x;
}
long double area(const P3&a,const P3&b)
{
	long double r1=a.y*b.z-a.z*b.y;
	long double r2=a.z*b.x-a.x*b.z;
	long double r3=a.x*b.y-a.y*b.x;
	return sqrt(r1*r1+r2*r2+r3*r3)/2;
}
int pr[1<<17];
P3 formula[1<<17];
int find(int u)
{
	if(pr[u]<0)return u;
	else return pr[u]=find(pr[u]);
}
void merge(int u,int v)
{
	u=find(u);
	v=find(v);
	if(u==v)return;
	if(-pr[u]<-pr[v])swap(u,v);
	pr[u]+=pr[v];
	pr[v]=u;
	formula[u]=formula[u]+formula[v];
}
map<pair<int,int>,int>surface;
vector<pair<int,int> >connect[1<<20];
vector<pair<int,P3> >change[1<<20];
long double ans[1<<17];
vector<pair<int,int> >qs[1<<20];
int sid[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>X[i]>>Y[i]>>Z[i];
		sid[i]=-1;
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		pr[i]=-1;
		formula[i]=P3();
		int id[3];
		for(int j=0;j<3;j++)cin>>id[j],id[j]--;
		sort(id,id+3,[](int l,int r){return Z[l]<Z[r];});
		sid[id[0]]=sid[id[1]]=sid[id[2]]=i;
		for(int j=0;j<3;j++)
		{
			int u=id[j];
			int v=id[(j+1)%3];
			if(u>v)swap(u,v);
			if(surface.find(make_pair(u,v))!=surface.end())
			{
				int to=surface[make_pair(u,v)];
				int hight=max(Z[u],Z[v]);
				connect[hight].push_back(make_pair(to,i));
			}
			else surface[make_pair(u,v)]=i;
		}
		P3 p1(id[0]),p2(id[1]),p3(id[2]);
		if(Z[id[0]]==Z[id[2]])
		{
			long double t=area(p2-p1,p3-p1);
			change[Z[id[0]]].push_back(make_pair(i,P3(t,0,0)));
		}
		else if(Z[id[0]]==Z[id[1]])
		{
			long double t=area(p2-p1,p3-p1);
			long double ordh=Z[id[2]]-Z[id[0]];
			P3 r(Z[id[2]]/ordh,-1/ordh,0);
			r=mul(r,r);
			change[Z[id[2]]].push_back(make_pair(i,r*t));
			change[Z[id[0]]].push_back(make_pair(i,r*-t+P3(t,0,0)));
		}
		else if(Z[id[1]]==Z[id[2]])
		{
			long double t=area(p2-p1,p3-p1);
			long double ordh=Z[id[2]]-Z[id[0]];
			P3 r(-Z[id[0]]/ordh,1/ordh,0);
			r=mul(r,r);
			change[Z[id[2]]].push_back(make_pair(i,r*-t+P3(t,0,0)));
			change[Z[id[0]]].push_back(make_pair(i,r*t));
		}
		else
		{
			P3 np=(p3-p1)*((long double)(Z[id[1]]-Z[id[0]])/(long double)(Z[id[2]]-Z[id[0]]))+p1;
			{
				long double t=area(p2-np,p3-np);
				long double ordh=Z[id[2]]-Z[id[1]];
				P3 r(Z[id[2]]/ordh,-1/ordh,0);
				r=mul(r,r);
				change[Z[id[2]]].push_back(make_pair(i,r*t));
				change[Z[id[1]]].push_back(make_pair(i,r*-t+P3(t,0,0)));
			}
			{
				long double t=area(p2-np,p1-np);
				long double ordh=Z[id[1]]-Z[id[0]];
				P3 r(-Z[id[0]]/ordh,1/ordh,0);
				r=mul(r,r);
				change[Z[id[1]]].push_back(make_pair(i,r*-t+P3(t,0,0)));
				change[Z[id[0]]].push_back(make_pair(i,r*t));
			}
		}
	}
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int h,p;
		cin>>h>>p;p--;
		qs[h].push_back(make_pair(i,p));
	}
	for(int h=1000000;h>=0;h--)
	{
		for(pair<int,int>q:qs[h])
		{
			if(Z[q.second]<=h)ans[q.first]=-1;
			else ans[q.first]=val(formula[find(sid[q.second])],h);
		}
		for(pair<int,int>e:connect[h])merge(e.first,e.second);
		for(pair<int,P3>p:change[h])
		{
			int u=find(p.first);
			formula[u]=formula[u]+p.second;
		}
	}
	cout<<fixed<<setprecision(16);
	for(int i=0;i<Q;i++)
	{
		if(ans[i]<0)cout<<"-1\n";
		else cout<<ans[i]<<"\n";
	}
}