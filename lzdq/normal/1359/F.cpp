#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=2.5e4+5;
const double eps=1e-7,lim=1e10,keps=1e-6;
typedef pair<double,int> pr;
#define mkp make_pair
int n;
double a[MAXN][5];
struct Seg{
	double x1,x2,b,k;
}b[MAXN];
pr c[MAXN*2];
inline bool Cross(int p,int q){
	double l=max(b[p].x1,b[q].x1),r=min(b[p].x2,b[q].x2);
	if(l>r) return 0;
	double x=(b[p].b+b[p].k*l)-(b[q].b+b[q].k*l),y=(b[p].b+b[p].k*r)-(b[q].b+b[q].k*r);
	return x>=-eps&&y<=eps || x<=eps&&y>=-eps;
}
double nowx;
struct Comp{
	bool operator ()(int x,int y){
		return b[x].b+b[x].k*nowx<b[y].b+b[y].k*nowx;
	}
};
set<int,Comp> s;
typedef set<int,Comp>::iterator iter;
iter its[MAXN];
bool Check(double tm){
	s.clear();
	for(int i=1; i<=n; i++){
		b[i].x1=a[i][0];
		b[i].x2=a[i][0]+tm*a[i][2];
		b[i].k=a[i][4];
		b[i].b=a[i][3];
		if(b[i].x1>b[i].x2)
			swap(b[i].x1,b[i].x2);
		c[i*2-1]=mkp(b[i].x1,-i);
		c[i*2]=mkp(b[i].x2,i);
	}
	/*
	for(int i=1; i<=n; i++)
		printf("%d x1 %f x2 %f k %f b %f\n",i,b[i].x1,b[i].x2,b[i].k,b[i].b);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(i==2&&j==3&&Cross(i,j)) return 1;
	puts("No");
	return 0;
	*/
	sort(c+1,c+n*2+1);
	for(int i=1; i<=n*2; i++){
		nowx=c[i].first;
		int j=abs(c[i].second);
		if(c[i].second<0){
			//puts("ins");
			auto it=s.upper_bound(j);
			if(it!=s.end()&&Cross(*it,j)) return 1;
			if(it!=s.begin()){
				it--;
				if(Cross(*it,j)) return 1;
			}
			its[j]=s.insert(j).first;
		}else{
			//puts("erase");
			auto it=its[j];
			s.erase(it);
			it=s.upper_bound(j);
			if(it!=s.end()&&Cross(*it,j)) return 1;
			if(it!=s.begin()){
				it--;
				if(Cross(*it,j)) return 1;
			}
		}
	}
	return 0;
}
int main(){
	/*
	b[1]=Seg{0,0,1,2};
	b[2]=Seg{0,1,1,0};
	if(Cross(1,2)) puts("Cross");
	else puts("No");
	return 0;
	freopen("in","r",stdin);
	*/
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		for(int j=0; j<5; j++)
			scanf("%lf",a[i]+j);
		double k=a[i][3]/a[i][2];
		double d=sqrt(a[i][2]*a[i][2]+a[i][3]*a[i][3]);
		a[i][2]=a[i][2]/d*a[i][4];
		a[i][4]=k;
		a[i][3]=a[i][1]-a[i][0]*k;
	}
	double l=0,r=lim;
	while(r-l>keps){
		double mid=(l+r)/2;
		if(Check(mid)) r=mid;
		else l=mid;
		//printf("l %.7f mid %.7f r %.7f\n",l,mid,r);
	}
	if(r>=lim-eps) puts("No show :(");
	else printf("%f\n",l);
	return 0;
}