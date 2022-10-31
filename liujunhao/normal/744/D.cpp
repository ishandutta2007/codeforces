#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
const double pi=acos(-1);
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
#define MAXN 1000
int n,m;
typedef pair<double,int>pdi;
pdi q[MAXN*4+10];
double dist[MAXN*2+10][MAXN*2+10],ang[MAXN*2+10][MAXN*2+10],ans;
struct point{
	int x,y;
	inline point(){
	}
	inline point(int x,int y):x(x),y(y){
	}
}a[MAXN*2+10];
inline int sqr(int x){
	return x*x;
}
inline int Get_sqdist(const point &a,const point &b){
	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
inline double Get_dist(const point &a,const point &b){
	return sqrt(Get_sqdist(a,b));
}
void read(){
	Read(n),Read(m);
	int i,j;
	for(i=1;i<=n+m;i++)
		Read(a[i].x),Read(a[i].y);
	for(i=1;i<=n+m;i++)
		for(j=1;j<=n+m;j++){
			dist[i][j]=Get_dist(a[i],a[j]);
			ang[i][j]=atan2(a[j].y-a[i].y,a[j].x-a[i].x);
		}
}
void fix(double &ang){
	if(ang<-pi)
		ang+=2*pi;
	else if(ang>=pi)
		ang-=2*pi;
}
bool check1(int pos,double mid){
	int i,cnt=0,bk=0;
	double d=2*mid,t,da,l,r;
	for(i=n+1;i<=n+m;i++){
		t=dist[pos][i]/d;
		if(t>=1)
			continue;
		da=acos(t);
		l=ang[pos][i]-da,r=ang[pos][i]+da;
		fix(l),fix(r);
		if(l>r)
			cnt++;
		q[++bk]=pdi(l,1);
		q[++bk]=pdi(r,-1);
	}
	sort(q+1,q+bk+1);
	if(!cnt)
		return 1;
	for(i=1;i<=bk;i++)
		if(!(cnt+=q[i].second))
			return 1;
	return 0;
}
bool check2(int pos,double mid){
	int i,cnt[2]={0},bk=0;
	double d=2*mid,t,da,l,r;
	for(i=1;i<=n+m;i++){
		if(i==pos)
			continue;
		t=dist[pos][i]/d;
		if(t>=1)
			continue;
		da=acos(t);
		l=ang[pos][i]-da,r=ang[pos][i]+da;
		fix(l),fix(r);
		if(l>r)
			cnt[i>n?1:0]++;
		q[++bk]=pdi(l,i>n?2:1);
		q[++bk]=pdi(r,i>n?-2:-1);
	}
	sort(q+1,q+bk+1);
	if(!cnt[1]&&cnt[0])
		return 1;
	for(i=1;i<=bk;i++){
		cnt[abs(q[i].second)-1]+=q[i].second>0?1:-1;
		if(!cnt[1]&&cnt[0])
			return 1;
	}
	return 0;
}
inline bool check(int pos,double mid){
	if(pos<=n)
		return check1(pos,mid);
	return check2(pos,mid);
}
double Divide_Conqure(double l,double r,int pos){
	int t=0;
	double mid;
	while(++t<50){
		mid=(l+r)/2;
		if(check(pos,mid))
			l=mid;
		else
			r=mid;
	}
	return l;
}
void solve(){
	int i;
	for(i=1;i<=n+m;i++){
		if(!check(i,ans))
			continue;
		ans=max(ans,Divide_Conqure(ans,1e10,i));
	}
}
int main()
{
	read();
	solve();
	if(ans<1e9)
		printf("%.10f\n",ans);
	else
		puts("-1");
}