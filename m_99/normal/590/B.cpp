#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

const double eps = 1e-10;

template <typename T>
struct vector_2d{
	T x,y,r,d;
	
	vector_2d(T a=0.0,T b=0.0){
		x = a;
		y = b;
		fix_rd();
	}
	
	void update_x(T a,T b){
		x = a*x + b;
		fix_rd();
	}
	
	void update_x(T a){
		update_x(0.0,a);
	}
	
	void update_y(T a,T b){
		y = a*y + b;
		fix_rd();
	}
	
	void update_y(T a){
		update_y(0.0,a);
	}
	
	void update_r(T a,T b){
		r = a*r + b;
		fix_xy();
	}
	
	void update_r(T a){
		update_r(0.0,a);
	}
	
	void update_d(T a,T b){
		d = a*d + b;
		fix_xy();
	}

	void update_d(T a){
		update_d(0.0,a);
	}
	
	void fix_xy(){
		x = r * cos(d);
		y = r * sin(d);
		fix_rd();
	}
	
	void fix_rd(){
		r = hypot(x,y);
		if(r==0.0)d=0.0;
		else d = atan2(y,x);
		fix_zero();
	}
	
	void fix_zero(){
		if(abs(x)<eps)x = 0.0;
		if(abs(y)<eps)y = 0.0;
		if(abs(r)<eps)r = 0.0;
		if(abs(d)<eps)d = 0.0;
	}
	
	void normalize(){
		T s = size();
		update_x(1.0/s,0.0);
		update_y(1.0/s,0.0);
	}
	
	
	T get_dis(vector_2d<T> V){
		return hypot(x-V.x,y-V.y);
	}
	
	T size(){
		return get_dis(vector_2d<T>());
	}
	
	T angle_difference(vector_2d<T> V){
		double ret = d - V.d;
		if(ret<-acos(-1.0))ret = acos(-1.0)*2.0+ret;
		if(ret>acos(-1.0))ret=-acos(-1.0)*2.0+ret;
		return ret;
	}
	
	//
	vector_2d get_midpoint(vector_2d<T> V){
		V.update_x(0.5,x/2.0);
		V.update_y(0.5,y/2.0);
		return V;
	}
	
	T get_inner_product(vector_2d<T> V){
		return x*V.x+y*V.y;
	}
	
	T get_cross_product(vector_2d<T> V){
		return x*V.y-y*V.x;
	}
	
	vector_2d &operator+=(const vector_2d<T> &another){
		update_x(1,another.x);
		update_y(1,another.y);
		return (*this);
	}
	
	vector_2d &operator-=(const vector_2d<T> &another){
		update_x(1,-another.x);
		update_y(1,-another.y);
		return (*this);
	}
	
	vector_2d operator+(const vector_2d<T> &another)const{
		return (vector_2d(*this)+=another);
	}
	
	vector_2d operator-(const vector_2d<T> &another)const{
		return (vector_2d(*this)-=another);
	}
	
	void show(){
		cout<<x<<','<<y<<endl;
	}
};

int main(){
	
	vector_2d<double> S,T;
	{
		double x,y;
		cin>>x>>y;
		S = vector_2d<double>(x,y);
	}
	{
		double x,y;
		cin>>x>>y;
		T = vector_2d<double>(x,y);
	}
	
	double vm,t;
	cin>>vm>>t;
	
	vector_2d<double> v,w;
	{
		double x,y;
		cin>>x>>y;
		v = vector_2d<double>(x,y);
	}
	{
		double x,y;
		cin>>x>>y;
		w = vector_2d<double>(x,y);
	}
	
	double ng = 0.0,ok = 1e16;
	
	rep(_,1000){
		double mid = (ok+ng)/2.0;
		vector_2d<double> X = T-S;
		if(mid>=t){
			X.x -= t*v.x;
			X.y -= t*v.y;
			X.x -= (mid-t)*w.x;
			X.y -= (mid-t)*w.y;
		}
		else{
			X.x -= mid*v.x;
			X.y -= mid*v.y;
		}
		
		if(X.size()>mid * vm)ng = mid;
		else ok = mid;
	}
	
	cout<<fixed<<setprecision(15)<<ok<<endl;
	
    return 0;
}