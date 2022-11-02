#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4002,M=4000002;
const double Eps=1e-10;
struct Nod{
	double x,y;
	bool t;
}p[N],q[N];
double Abs(double x){
	return x>0?x:-x;
}
struct Line{
	double k,b;
	bool operator<(const Line &f)const {
		if(Abs(f.k-k)<Eps)
			return f.b<b;
		return f.k<k;
	}
}g[M];
int T,n,m,i,j,s1,s2,Ans,cnt,a,tmp;
double X,Y,A,B,k,b;
bool cmp(Nod u,Nod v){
	if(Abs(u.x-v.x)>Eps)
		return u.x<v.x;
	return u.y<v.y;
}
void init(){
	X=Y=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].t=1;
		X+=p[i].x;Y+=p[i].y;
	}
	X/=n;Y/=n;
	for(i=1;i<=n;i++){
		p[i+n].x=X*2-p[i].x;
		p[i+n].y=Y*2-p[i].y;
		p[i+n].t=0;
	}
	n*=2;
	sort(p+1,p+n+1,cmp);
	m=0;
	p[n+1].x=-1<<30;
	for(i=1;i<=n;i++){
		s1=s2=0;
		for(j=i-1;Abs(p[i].x-p[j+1].x)<Eps&&Abs(p[i].y-p[j+1].y)<Eps;){
			j++;
			if(p[j].t)
				s1++;
			else
				s2++;
		}
		if(s1&&!s2)
			q[++m]=p[i];
		i=j;
	}
	n=m;	
}
bool cmp2(Nod u,Nod v){
	return u.y-u.x*k<v.y-v.x*k;
}
double Get(int u,int v){
	if(k>1e18)
		return p[u].x-p[v].x;
	return (p[u].y-p[u].x*k)-(p[v].y-p[v].x*k);
}
void work(){
	Ans=0;
	if(n<=2){
		printf("-1\n");
		return;
	}
	cnt=0;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			A=1.0*(q[i].x+q[j].x)/2;
			B=1.0*(q[i].y+q[j].y)/2;
			if(Abs(A-X)>Eps){
				k=(B-Y)/(A-X);
				b=Y-k*X;
			}
			else{
				k=1e20;
				b=Y-k*X;
			}
			g[++cnt]=(Line){k,b};
		}
	sort(g+1,g+cnt+1);
	g[cnt+1].k=1e20;
	for(i=1;i<=cnt;i++){
		for(j=i;j<cnt&&Abs(g[j+1].k-g[j].k)<Eps&&Abs(g[j+1].b-g[j].b)<Eps;j++);
		if(j-i+1>=n/2){
			i=j;
			k=g[j].k;
			
			for(a=1;a<=n;a++)
				p[a]=q[a];
			sort(p+1,p+n+1,cmp2);
			tmp=1;
			for(a=1;a<n-a+1;a++)
			if(Abs(Get(a,a+1)-Get(n-a,n-a+1))>1e-5)
				tmp=0;
			if(tmp)
				Ans++;
		}
		else
			i=j;
	}
	printf("%d\n",Ans);
}			
int main(){
	//scanf("%d",&T);
	//while(T--){
		init();
		work();
	//}
	return 0;
}