#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1e20

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
	
	
	T get_dis(vector_2d<T> V){
		return hypot(x-V.x,y-V.y);
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

//ax+by+c=0
template <typename T>
struct line{
	T a,b,c;
	line(T A,T B,T C){
		a=A,b=B,c=C;
	}
	
	line(vector_2d<T> V,T A,T B){
		a = A;
		b = B;
		c = -a*V.x - b*V.y;
	}
	
	line(vector_2d<T> V1=vector_2d<T>(),vector_2d<T> V2=vector_2d<T>()):line(V1,-(V1.y-V2.y),V1.x-V2.x){
	}

	
	void fix_abc(){
		T l = hypot(a,b);
		a/=l;b/=l;c/=l;
		T X = a;
		if(abs(X)<eps)X=b;
		if(abs(X)<eps)X=c;
		if(X<0.0){
			a*=-1;
			b*=-1;
			c*=-1;
		}
	}
	
	T get_signed_dis(vector_2d<T> V){
		return (a*V.x+b*V.y+c)/hypot(a,b);
	}
	
	T get_dis(vector_2d<T> V){
		return abs(get_signed_dis(V));
	}
	
	vector_2d<T> get_projection(vector_2d<T> P){
		line L(P,-b,a);
		return get_cross_point(L);
	}
	
	vector_2d<T> get_cross_point(line<T> L){
		vector_2d<T> ret(1e20,1e20);

		if(abs(L.a*b-a*L.b)>=eps){
			ret.update_x((L.b*c-b*L.c)/(L.a*b-a*L.b));
			ret.update_y((a*L.c-L.a*c)/(L.a*b-a*L.b));
		}

		return ret;
	}
	
	void show(){
		cout<<a<<','<<b<<','<<c<<endl;
	}
	
};

template <typename T>
struct segment{
	vector_2d<T> V1,V2;
	segment(vector_2d<T> a=vector_2d<T>(),vector_2d<T> b=vector_2d<T>()){
		V1=a;
		V2=b;
	}
	
	T get_dis(vector_2d<T> P){
		T ret = P.get_dis(V1);
		ret = min(ret,P.get_dis(V2));
		line<T> L(V1,V2);
		vector_2d<T> Q = L.get_projection(P);
		if(Q.x+eps>min(V1.x,V2.x)&&Q.y+eps>min(V1.y,V2.y)&&Q.x<max(V1.x,V2.x)+eps&&Q.y<max(V1.y,V2.y)+eps)ret = min(ret,Q.get_dis(P));
		return ret;
	}
	
	T get_dis(segment<T> l){
		if(get_cross_point(l).x<1e20)return 0.0;
		return min({get_dis(l.V1),get_dis(l.V2),l.get_dis(V1),l.get_dis(V2)});
	}
	
	vector_2d<T> get_cross_point(segment<T> l){
		if(get_dis(l.V1)<eps)return l.V1;
		if(get_dis(l.V2)<eps)return l.V2;
		if(l.get_dis(V1)<eps)return V1;
		if(l.get_dis(V2)<eps)return V2;
		line<T> L1(V1,V2),L2(l.V1,l.V2);
		vector_2d<T> P = L1.get_cross_point(L2);
		if(get_dis(P)<eps&&l.get_dis(P)<eps)return P;
		return vector_2d<T> (1e20,1e20);
	}
};

template <typename T>
struct triangle{
	vector_2d<T> V[3];
	
	triangle(vector_2d<T> V1,vector_2d<T> V2,vector_2d<T> V3){
		V[0] = V1;
		V[1] = V2;
		V[2] = V3;
	}
	
	vector_2d<T> get_circumcenter(){
		line<T> L1(V[0],V[1]);
		vector_2d<T> M1 = V[0].get_midpoint(V[1]);
		L1 = line<T>(M1,L1.b,L1.a);

		line<T> L2(V[1],V[2]);
		vector_2d<T> M2 = V[1].get_midpoint(V[2]);
		L2 = line<T>(M2,L2.b,L2.a);
				
		return L1.get_cross_point(L2);
	}
	
	T get_signed_area(){
		return ((V[1].x-V[0].x)*(V[2].y-V[0].y) - (V[2].x-V[0].x)*(V[1].y-V[0].y))/2.0;
	}
	
	T get_area(){
		return abs(get_signed_area());
	}
	
	bool is_inside(vector_2d<T> P){
		T S = triangle<T>(V[0],V[1],P).get_area() + triangle<T>(V[1],V[2],P).get_area() + triangle<T>(V[2],V[0],P).get_area();
		return abs(S - get_area())<eps;
	}
	
	bool is_clockwise(){
		vector_2d<T> X = V[1]-V[0],Y = V[2]-V[1];
		return X.x*Y.y-X.y*Y.x < 0.0;
	}
	
};

template <typename T>
struct polygon{
	vector<vector_2d<T>> V;
	polygon(vector<vector_2d<T>> v){
		V = v;
	}
	
	bool is_convex(){
		bool f = false;
		for(int i=0;i<V.size();i++){
			triangle<T> tri(V[i],V[(i+1)%V.size()],V[(i+2)%V.size()]);
			if(i==0)f = tri.is_clockwise();
			else{
				if(tri.is_clockwise()!=f)return false;
			}
		}
		return true;
	}
	
	T get_signed_area(){
		T ret = 0.0;
		for(int i=1;i<V.size()-1;i++){
			triangle<T> tri(V[0],V[i],V[i+1]);
			ret += tri.get_signed_area();
		}
		return ret;
	}
	
	T get_area(){
		return abs(get_signed_area());
	}
	
	T get_diameter(){
		vector<T> dis(V.size());
		int now = 0;
		for(int i=0;i<V.size();i++){
			while(true){
				int next = (now+1)%V.size();
				if(V[i].get_dis(V[now])<V[i].get_dis(V[next])+eps){
					now = next;
					continue;
				}
				else{
					break;
				}
			}
			dis[i] = V[i].get_dis(V[now]);
		}
		
		T ret = 0.0;
		for(int i=0;i<V.size();i++)ret = max(ret,dis[i]);
		
		return ret;
	}
	
	bool is_on_side(vector_2d<T> P){
		for(int i=0;i<V.size();i++){
			segment<T> l(V[i],V[(i+1)%V.size()]);
			if(l.get_dis(P)<eps)return true;
		}
		return false;
	}
	
	bool is_inside(vector_2d<T> P){
		if(is_on_side(P))return true;
		double R = 0.0;
		for(int i=0;i<V.size();i++){
			vector_2d<T> p1(V[i]-P),p2(V[(i+1)%V.size()]-P);
			R += p1.angle_difference(p2);
		}
		return abs(R)>=eps;
	}
};

template <typename T>
struct circle{
	vector_2d<T> C;
	T R;
	circle(vector_2d<T> c=vector_2d<T>(),T r=0.0){
		C = c;
		R = r;
	}
	
	vector<vector_2d<T>> get_cross_point(circle<T> C2){
		vector<vector_2d<T>> ret;

		T d = C.get_dis(C2.C);
		if(d>R+C2.R+eps)return ret;
		if(d+eps<abs(R-C2.R))return ret;
		T cosine = (pow(R,2.0)+pow(d,2.0)-pow(C2.R,2.0))/(2.0*R*d);
		
		T Rc = R*cosine;
		T Rs = sqrt(pow(R,2.0)-pow(Rc,2.0));
		
		vector_2d<T> e1 = (C2.C-C);
		e1.update_r(1.0/d,0.0);
		vector_2d<T> e2 = e1;
		e2.update_d(1.0,acos(-1.0)/2.0);
		e1.update_r(Rc,0.0);
		e2.update_r(Rs,0.0);
		ret.push_back(C + e1+e2);
		e2.update_d(1.0,-acos(-1.0));
		ret.push_back(C+e1+e2);
		return ret;
	}
};

vector<int> get_CH(vector<vector_2d<double>> &v){
	vector<pair<vector_2d<double>,int>> V(v.size());
	for(int i=0;i<v.size();i++){
		V[i].first=v[i];
		V[i].second=i;
	}
	
	sort(V.begin(),V.end(),[](auto &a,auto &b){
		if(abs(a.first.y-b.first.y)>eps)return a.first.y<b.first.y;
		return a.first.x<b.first.x;
	});
	
	vector<int> ret;
	
	for(int i=0;i<V.size();i++){
		if(ret.size()<2){
			ret.push_back(i);
		}
		else{
			vector_2d<double> v1 = V[ret[ret.size()-2]].first,v2 = V[ret[ret.size()-1]].first,v3 = V[i].first;
			v3 -= v2;
			v2 -= v1;
			if(v2.get_cross_product(v3)>-eps){
				ret.push_back(i);
			}
			else{
				ret.pop_back();
				i--;
				continue;
			}
		}
	}

	for(int i=(int)V.size()-2;i>=0;i--){
		if(ret.size()<2){
			ret.push_back(i);
		}
		else{
			vector_2d<double> v1 = V[ret[ret.size()-2]].first,v2 = V[ret[ret.size()-1]].first,v3 = V[i].first;
			v3 -= v2;
			v2 -= v1;
			if(v2.get_cross_product(v3)>-eps){
				ret.push_back(i);
			}
			else{
				ret.pop_back();
				i++;
				continue;
			}
		}
	}
	ret.pop_back();
	for(int i=0;i<ret.size();i++)ret[i] = V[ret[i]].second;
	set<int> S;
	{
		vector<int> ret2;
		for(int i=0;i<ret.size();i++){
			if(S.count(ret[i]))continue;
			ret2.push_back(ret[i]);
			S.insert(ret[i]);
		}
		ret = ret2;
	}
	return ret;
	
}

int main(){

	int n;
	double x,y;
	cin>>n>>x>>y;
	
	double mini = Inf,maxi = 0.0;
	vector<vector_2d<double>> V;
	for(int i=0;i<n;i++){
		double a,b;
		cin>>a>>b;
		
		double d = sqrt(pow(x-a,2.0)+pow(y-b,2.0));
		mini = min(mini,d);
		maxi = max(maxi,d);
		V.push_back(vector_2d<double>(a,b));
	}
	
	for(int i=0;i<n;i++){
		segment<double> S(V[i],V[(i+1)%n]);
		mini = min(mini,S.get_dis(vector_2d<double>(x,y)));
	}
	
	vector<int> X = get_CH(V);
	{
		vector<vector_2d<double>> V2;
		for(int i=0;i<X.size();i++){
			V2.push_back(V[X[i]]);
		}
		V = V2;
	}
	polygon<double> C(V);
	double S = acos(-1.0)*pow(maxi,2.0);
	if(!C.is_inside(vector_2d(x,y))){
		S -= acos(-1.0)*pow(mini,2.0);
	}
	
	cout<<fixed<<setprecision(10)<<S<<endl;
	
	return 0;
}