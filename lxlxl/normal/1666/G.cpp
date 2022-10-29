#include<bits/stdc++.h>
using namespace std;

const int maxn = 210000;
typedef long long ll;
typedef long double db;

int n,m,Q;
int zi[maxn];
struct point
{
	db x,y,z;
	point operator + (point k1){return (point){x+k1.x,y+k1.y,z+k1.z};}
	point operator - (point k1){return (point){x-k1.x,y-k1.y,z-k1.z};}
	point operator * (db k1){return (point){x*k1,y*k1,z*k1};}
}p[maxn];

struct node
{
	db a,b,c;
	int l,r;
};

namespace LWN{
	typedef long double db;
	const db eps=1e-8;
	int sign(db k){
		if (k<-eps) return -1;
		if (k>eps) return 1;
		return 0;
	}
	int cmp(db k1,db k2){return sign(k1-k2);}
	db area(point k1,point k2){
		db x=(db)1.0*k1.y*k2.z-(db)1.0*k1.z*k2.y;
		db y=(db)1.0*k1.z*k2.x-(db)1.0*k1.x*k2.z;
		db z=(db)1.0*k1.x*k2.y-(db)1.0*k1.y*k2.x;
		return hypot(hypot(x,y),z)/2.0;
	}
	pair<node,node> calc(point A,point B,point C){
		vector<point> v;
		v.push_back(A);
		v.push_back(B);
		v.push_back(C);
		sort(v.begin(),v.end(),[](const point &P,const point &Q){return P.z<Q.z;});
		A=v[0];
		B=v[1];
		C=v[2];
		if (cmp(A.z,C.z)==0){
			db S=area(C-A,C-B);
			node n1=(node){0.,0.,S,A.z,B.z};
			node n2=(node){0.,0.,0.,B.z,C.z};
			return make_pair(n1,n2);
		}
		point M=A*((C.z-B.z)/(C.z-A.z))+C*((B.z-A.z)/(C.z-A.z));
		node n1=(node){0.,0.,0.,A.z,B.z};
		node n2=(node){0.,0.,0.,B.z,C.z};
		if (A.z!=B.z){
			db s1=area(B-A,M-A)/(B.z-A.z)/(B.z-A.z);
			n1=(node){-s1, 2.*s1*A.z , s1*(B.z*B.z-2.*B.z*A.z) ,A.z,B.z};
		}
		if (B.z!=C.z){
			db s2=area(C-M,C-B)/(C.z-B.z)/(C.z-B.z);
			n2=(node){s2, -2.*s2*C.z , s2*(C.z*C.z) ,B.z,C.z};
		}
		return make_pair(n1,n2);
	}
}

db ans[maxn];
vector< pair<int,int> >Ve[1010000];
vector< pair<int,node> >Add[1010000],Dec[1010000];
vector< pair<int,int> >qi[1010000];
int fa[maxn];
db fas[maxn];
node kp[maxn];
int findfa(const int x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>p[i].x>>p[i].y>>zi[i];
		p[i].z = zi[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++) 
	{
		int x,y,z; cin>>x>>y>>z;
		if(zi[x]<zi[y]) swap(x,y);
		if(zi[x]<zi[z]) swap(x,z);
		if(zi[y]<zi[z]) swap(y,z);
		
		//xy
			Ve[min(zi[x],zi[y])].emplace_back(x,y);
		//xz
			Ve[min(zi[x],zi[z])].emplace_back(x,z);
		//yz
			Ve[min(zi[y],zi[z])].emplace_back(y,z);
			
		auto temp = LWN::calc(p[x],p[y],p[z]);
		node f1=temp.first, f2=temp.second;
		Add[f1.r].emplace_back((f1.r==zi[x]?x:(f1.r==zi[y]?y:z)),f1);
		Dec[f1.l].emplace_back((f1.r==zi[x]?x:(f1.r==zi[y]?y:z)),f1);
		Add[f2.r].emplace_back((f2.r==zi[x]?x:(f2.r==zi[y]?y:z)),f2);
		Dec[f2.l].emplace_back((f2.r==zi[x]?x:(f2.r==zi[y]?y:z)),f2);
	}
	
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		int h,p; cin>>h>>p;
		qi[h].emplace_back(i,p);
	}
	
	for(int i=1;i<=n;i++) fa[i]=i,fas[i]=0;
	for(int h=1000000;h>=0;h--)
	{
		for(auto temp:qi[h])
		{
			int i=temp.first,x=temp.second;
			if(zi[x]<=h) ans[i]=-1;
			else
			{
				int ff=findfa(x);
				ans[i]= fas[ff] + kp[ff].a*h*h + kp[ff].b*h + kp[ff].c;
			}
		}
		
		for(auto e:Ve[h])
		{
			int x=e.first,y=e.second;
			int f1=findfa(x),f2=findfa(y);
			if(f1!=f2)
			{
				fa[f2]=f1;
				fas[f1]+=fas[f2];
				kp[f1].a+=kp[f2].a;
				kp[f1].b+=kp[f2].b;
				kp[f1].c+=kp[f2].c;
			}
		}
		for(auto ad:Add[h])
		{
			int x=ad.first; node k=ad.second;
			int ff=findfa(x);
			kp[ff].a+= k.a;
			kp[ff].b+= k.b;
			kp[ff].c+= k.c;
		}
		for(auto de:Dec[h])
		{
			int x=de.first; node k=de.second;
			int ff=findfa(x);
			
			fas[ff]+= k.a*h*h + k.b*h + k.c;
			kp[ff].a-= k.a;
			kp[ff].b-= k.b;
			kp[ff].c-= k.c;
		}
	}
	
	for(int i=1;i<=Q;i++) 
	{
		if(ans[i]<-0.5) cout<<"-1\n";
		else cout<<fixed<<setprecision(12)<<ans[i]<<'\n';
	}
	
	return 0;
}