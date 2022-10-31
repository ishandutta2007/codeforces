#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int px,py,n,tx[100010],ty[100010];
long long mx;
double mi;
void Read(int &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
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
long long Get_dist(int x1,int y1,int x2,int y2){
	return 1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2);
}
double Get_dist(double x1,double y1,double x2,double y2){
	return 1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2);
}
double Get_dist(int x1,int y1,int x2,int y2,int x3,int y3){
	if(x1==x2){
		if(y3>max(y1,y2)&&y3<min(y1,y2))
			return min(Get_dist(x1,y1,x3,y3),Get_dist(x2,y2,x3,y3));
		return 1ll*(x1-x3)*(x1-x3);
	}
	if(y1==y2){
		if(x3>max(x1,x2)||x3<min(x1,x2))
			return min(Get_dist(x1,y1,x3,y3),Get_dist(x2,y2,x3,y3));
		return 1ll*(y1-y3)*(y1-y3);
	}
	double k=1.0*(y1-y2)/(x1-x2);
	double x=(k*k*x1+k*(y3-y1)+x3)/(k*k+1),y=k*(x-x1)+y1;
	if(x>max(x1,x2)||x<min(x1,x2))
		return min(Get_dist(x1,y1,x3,y3),Get_dist(x2,y2,x3,y3));
	return Get_dist(1.0*x3,1.0*y3,x,y);
}
int main()
{
	Read(n),Read(px),Read(py);
	int i;
	mx=0,mi=1e19;
	for(i=1;i<=n;i++){
		Read(tx[i]),Read(ty[i]);
		mx=max(mx,Get_dist(tx[i],ty[i],px,py));
	}
	for(i=1;i<=n;i++){
		mi=min(mi,Get_dist(tx[i],ty[i],tx[i%n+1],ty[i%n+1],px,py));
	}
	printf("%.18lf",acos(-1)*(mx-mi));
}