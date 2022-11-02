#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1600002;
typedef long long ll;
const long double eps=1000,Eps=1e-8;
struct Uzi{
	int x,y;
	bool operator<(const Uzi &k)const{
		if(k.x!=x)
			return k.x>x;
		return k.y>y;
	}
}p[N];
int n,m,x[N],y[N],i,cnt,ans;
long long d[N],D[N],s8,s9;
long double Cx,Cy,Sxy,Sd,R;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i),Cx+=x[i],Cy+=y[i];
	Cx/=n;Cy/=n;
	for(i=1;i<=n;i++)
		Sxy+=(Cx-x[i])*(Cx-x[i])+(Cy-y[i])*(Cy-y[i]);
}
void Check(ll X,ll Y){
	int i;
	if(fabs((X-Cx)*(X-Cx)+(Y-Cy)*(Y-Cy)-R)>eps)
		return;
	//printf("%lld %lld\n",X,Y);
	for(i=1;i<=n;i++)
		D[i]=1ll*(X-x[i])*(X-x[i])+1ll*(Y-y[i])*(Y-y[i]);
	sort(D+1,D+n+1);
	for(i=1;i<=n;i++)
		if(D[i]!=d[i])
			return;
	cnt++;
	p[cnt]=(Uzi){(int)X,(int)Y};
}
void GetNode(long double X1,long double Y1,long double R1,long double X2,long double Y2,long double R2,long double R12,long double R22){
	long double dis=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	long double dis2=(X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);		
	//printf("   %lf %lf %lf\n",dis,R1,R2);
	if(dis>R1+R2+Eps)return;
	long double t=atan2(Y2-Y1,X2-X1);
	long double p=(R12+dis2-R22)/2/R1/dis;
	if(p>1)p=1;
	if(p<-1)p=-1;
	long double k=acos(p);
	long double X3=X1+R1*cos(t+k);
	long double Y3=Y1+R1*sin(t+k);
	//printf("%.6Lf %.6Lf %.6Lf %.6Lf %.6Lf %.6Lf %.6Lf\n",R1,R2,dis,t,k,X3,Y3);
	int u,v;
	if(fabs(X3)<(1e10)&&fabs(Y3)<(1e10)){
		for(u=-5;u<=5;u++)
			for(v=-5;v<=5;v++){
				Check((ll)(X3+u),(ll)(Y3+v));
				//Check((ll)(X3+u+0.6),(ll)(Y3+v+0.6));
			}
	}	
	long double X4=X1+R1*cos(t-k);
	long double Y4=Y1+R1*sin(t-k);
	if(fabs(X4)<(1e10)&&fabs(Y4)<(1e10)){
		for(u=-5;u<=5;u++)
			for(v=-5;v<=5;v++){
				Check((ll)(X4+u),(ll)(Y4+v));	
				//Check((ll)(X4+u+0.6),(ll)(Y4+v+0.6));	
			}
	}
}
void work(){
	cnt=0;Sd=0;ans=0;
	s8=s9=0;
	for(i=1;i<=n;i++){
		scanf("%lld",d+i);
		s8+=d[i]/1000000000;
		s9+=d[i]%1000000000;
	}
	sort(d+1,d+n+1);
	d[0]=233333333;
	R=(((long double)s8)*((long double)1000000000)+((long double)s9)-Sxy)/n;
	//printf("%lf %lf %lf\n\n",R,Cx,Cy);
	for(i=1;i<=n;i++)
		if(d[i]!=d[i-1])
			GetNode(Cx,Cy,sqrt(R),x[1],y[1],sqrt(d[i]),R,d[i]);
	p[0].x=p[0].y=192608170;
	sort(p+1,p+cnt+1);
	for(i=1;i<=cnt;i++)
		if(p[i].x!=p[i-1].x||p[i].y!=p[i-1].y)
			ans++;
	printf("%d ",ans);
	for(i=1;i<=cnt;i++)
		if(p[i].x!=p[i-1].x||p[i].y!=p[i-1].y)
			printf("%d %d ",p[i].x,p[i].y);
	printf("\n");
}
int main(){
	init();
	scanf("%d",&m);
	while(m--)
		work();
	//while(1);
	return 0;
}