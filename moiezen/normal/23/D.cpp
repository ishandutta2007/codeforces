#include <cstdio>
struct Point{
	double x,y;
};
Point operator+(Point a,Point b){
	Point res;
	res.x=a.x+b.x;
	res.y=a.y+b.y;
	return res;
}
Point operator-(Point a,Point b){
	Point res;
	res.x=a.x-b.x;
	res.y=a.y-b.y;
	return res;
}
double operator*(Point a,Point b){
	return 1LL*a.x*b.y-1LL*a.y*b.x;
}
int clk(Point o,Point a,Point b){
	if((a-o)*(b-o)<-0.01) return 1;
	if((a-o)*(b-o)>0.01) return -1;
	return 0;
}
void equa(double a,double b,double c,double d,double e,double f,double&x,double&y){
	x=(b*f-c*e)/(b*d-a*e);
	y=(a*f-c*d)/(a*e-b*d);
}
void getO(double a,double b,double c,double d,double e,double f,double&x,double&y){
	equa(2*(a-c),2*(b-d),a*a+b*b-c*c-d*d,2*(a-e),2*(b-f),a*a+b*b-e*e-f*f,x,y);
}
Point O(Point a,Point b,Point c){
	Point res;
	getO(a.x,a.y,b.x,b.y,c.x,c.y,res.x,res.y);
	return res;
}
void getall(Point p,Point q,Point r,Point&a,Point&b,Point&c,Point&d,bool&ok){
	if(!clk(p,q,r)&&!clk(p,r,q)){
		ok=false;
		return;
	}
	b=O(p,q,q+q-r);
	a=p+p-b;
	c=q+q-b;
	d=r+r-c;
	int t1=clk(a,b,c),t2=clk(b,c,d),t3=clk(c,d,a),t4=clk(d,a,b);
	ok=t1==t2&&t2==t3&&t3==t4;
}
Point p,q,r,a,b,c,d;
bool ok;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y,&r.x,&r.y);
		getall(p,q,r,a,b,c,d,ok);
		if(!ok){
			getall(q,r,p,a,b,c,d,ok);
			if(!ok) getall(r,p,q,a,b,c,d,ok);
		}
		if(ok) printf("YES\n%.9f %.9f %.9f %.9f %.9f %.9f %.9f %.9f\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
		else printf("NO\n\n");
	}
	
}