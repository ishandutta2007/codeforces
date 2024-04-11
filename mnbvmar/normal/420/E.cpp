#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <limits.h>
#define MP make_pair
#define M_PI 3.141592653589793

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int,int> VII;
const LD Eps = 1e-10;



//**** LIBRARY ****//

/// OBSLUGA typu long double
inline bool _is_zero(LD x){
	return (x >= -Eps) && (x <= Eps);
}
inline bool _is_zero(LD x, LD __Eps){
	return (x >= -__Eps) && (x <= __Eps);
}
inline int _sign(LD x){
	return (_is_zero(x) ? 0 : (x > 0 ? 1 : -1));
}
inline int _sign(LD x, LD __Eps){
	return (_is_zero(x, __Eps) ? 0 : (x > 0 ? 1 : -1));
}



/// STRUKTURY DANYCH
struct Point;
struct Vector;
struct Segment;
struct Circle;

struct Point {
	LD x, y;
	
	Point(LD _x=0, LD _y=0) : x(_x), y(_y) {}
	bool operator==(const Point P) const {
		return _is_zero(x-P.x) && _is_zero(y-P.y);
	}
	bool operator<(const Point P) const {
		if(_is_zero(x-P.x))
			return _sign(y-P.y) < 0;
		else
			return x < P.x;
	}
	Point operator+(const Vector V) const;
	Point operator-(const Vector V) const;
	Vector operator-(const Point P) const;
	
	LD dist(const Point P) const;
	
	void debug(bool newline=false) const {
		printf("(%Lf, %Lf)", x, y);
		if(newline) printf("\n");
	}
};


struct Vector {
	LD x, y;
	Vector(LD _x=0, LD _y=0) : x(_x), y(_y) {}
	Vector(const Point P) : x(P.x), y(P.y) {}
	
	Vector operator+(const Vector V) const {
		return Vector(x+V.x, y+V.y);
	}
	Vector operator-(const Vector V) const {
		return Vector(x-V.x, y-V.y);
	}
	Point operator+(const Point P) const {
		return Point(x+P.x, y+P.y);
	}
	Point operator-(const Point P) const {
		return Point(x-P.x, y-P.y);
	}
	bool operator==(const Vector V) const {
		return _is_zero(x-V.x) && _is_zero(y-V.y);
	}
	// iloczyn skalarny
	LD dot_prod(const Vector V) const {
		return x*V.x + y*V.y;
	}
	LD operator*(const Vector V) const {
		return x*V.x + y*V.y;
	}
	// iloczyn wektorowy
	LD cross_prod(const Vector V) const {
		return x*V.y - y*V.x;
	}
	LD operator^(const Vector V) const {
		return x*V.y - y*V.x;
	}
	
	LD length() const;
	void normalize(){
		LD l = length();
		x /= l; y /= l;
	}
	
	void debug(bool newline=false) const {
		printf("(%Lf, %Lf)", x, y);
		if(newline) printf("\n");
	}
};

Point Point::operator+(const Vector V) const {
	return Point(x+V.x, y+V.y);
}
Point Point::operator-(const Vector V) const {
	return Point(x-V.x, y-V.y);
}
Vector Point::operator-(const Point P) const {
	return Vector(x-P.x, y-P.y);
}

Vector operator*(const Vector V, const LD f){
	return Vector(V.x*f, V.y*f);
}
Vector operator*(const LD f, const Vector V){
	return Vector(V.x*f, V.y*f);
}


struct Segment {
	Point A, B;
	Segment(Point _A=Point(), Point _B=Point()) : A(_A), B(_B) {}
	
	LD length() const;
	
	bool operator==(const Segment S) const {
		return (A == S.A && B == S.B) || (A == S.B && B == S.A);
	}
	
	void debug(bool newline=false) const {
		printf("A=(%Lf, %Lf), B=(%Lf, %Lf)", A.x,A.y, B.x,B.y);
		if(newline) printf("\n");
	}
};

struct Line {
	Point O;
	Vector dir;
	Line(Point _O=Point(), Vector _dir=Vector()) : O(_O), dir(_dir) {
		#ifdef NORMALIZE_LINE_VECTORS
		dir.normalize();
		#endif
	}
	Line(Point _A, Point _B) : O(_A), dir(_B-_A) {
		#ifdef NORMALIZE_LINE_VECTORS
		dir.normalize();
		#endif
	}
	Line(Segment _S) : O(_S.A), dir(_S.B - _S.A) {
		#ifdef NORMALIZE_LINE_VECTORS
		dir.normalize();
		#endif
	}
	void operator=(const Line L){
		O = L.O; dir = L.dir;
		#ifdef NORMALIZE_LINE_VECTORS
		dir.normalize();
		#endif
	}
	bool operator==(const Line L) const;
	
	void debug(bool newline=false) const {
		printf("O=(%Lf, %Lf), dir=(%Lf, %Lf)", O.x,O.y, dir.x,dir.y);
		if(newline) printf("\n");
	}
	vector<LD> get_canonical(LD mul = 1.0){
		vector<LD> V;
		if(_is_zero(dir.x)){
			V.push_back(1); V.push_back(0); V.push_back(O.x);
		} else {
			V.push_back(dir.y/dir.x);
			V.push_back(1);
			V.push_back(-(O.y + dir.y/dir.x * O.x));
		}
		V[0] *= mul; V[1] *= mul; V[2] *= mul;
		return V;
	}
};

struct Circle {
	Point O;
	LD r;
	Circle(Point _O=Point(), LD _r = 1) : O(_O), r(_r) {}
	Circle(Point _O, Point _A) :
		O(_O), r(_O.dist(_A)) {}
		
	bool operator==(const Circle C) const {
		return (O == C.O) && _is_zero(r - C.r);
	}
	
	void debug(bool newline=false) const {
		printf("O=(%Lf, %Lf), r=%Lf", O.x,O.y, r);
		if(newline) printf("\n");
	}
};

LD Vector::length() const {
	return sqrt(x*x + y*y);
}
LD dist(const Point A, const Point B){
	return (B-A).length();
}
LD Point::dist(const Point P) const {
	return (*this - P).length();
}
LD Segment::length() const {
	return (B-A).length();
}

Point point_in_dist(const Line L, double d){ // d<0 - przeciwnie do wektora
	Vector V = L.dir;
	double vLength = V.length();
	
	return L.O + V * (d/vLength);
}

LD angle(const Vector A, const Vector B){
	return atan2l(A^B, A*B);
}
Point rotate(const Point P, const LD alpha){ // (w radianach)
	LD s = sin(alpha), c = cos(alpha);
	return Point(P.x*c - P.y*s, P.x*s + P.y*c);
}
Point rotate(const Point P, const LD alpha, const Point O){
	Vector VO = Vector(O);
	return rotate(P-VO, alpha) + VO;
}

int num_common_tangents(const Circle C, const Circle D){
	if(C.O == D.O && _is_zero(C.r-D.r))
		return INT_MAX;  // pokrywaja sie
	
	LD d = C.O.dist(D.O), cr = C.r, dr = D.r;
	
	int s1, s2;
	
	s1 = _sign(cr+d-dr);
	s2 = _sign(dr+d-cr);
	
	if(s1 != 1 || s2 != 1){
		// cos z wewnetrznoscia
		if(s1 == 0 || s2 == 0)
			return 1;  // styczne
		else
			return 0;  // rozlaczne
	}
	return _sign(d - cr - dr) + 3;
}

int intersect(const Circle C, const Circle D, Point &P1, Point &P2){
	int numTangents = num_common_tangents(C, D);
	if(numTangents == 0 || numTangents == 4){ // rozlaczne
		return 0;
	}
	if(numTangents == INT_MAX){
		return INT_MAX;
	}
	if(numTangents == 1 || numTangents == 3){ // styczne
		if(C.r >= D.r)
			P1 = point_in_dist(Line(C.O, D.O), C.r);
		else
			P1 = point_in_dist(Line(D.O, C.O), D.r);
		P2 = P1;
		return 1;
	}
	// kat miedzy jednym punktem przeciecia, jednym srodkiem i drugim
	//    (A, C.O, D.O) z tw. cosinusow w tym trojkacie
	LD d = C.O.dist(D.O);
	LD cosalpha = (C.r*C.r + d*d - D.r*D.r) / (2*C.r*d);
	LD alpha = acos(cosalpha);
	
	// znajdujemy punkty, obracajac prosta C.O-D.O o kat alpha i -alpha
	P1 = point_in_dist(Line(C.O, rotate(D.O, alpha, C.O)), C.r);
	P2 = point_in_dist(Line(C.O, rotate(D.O,-alpha, C.O)), C.r);
	return 2;
}






int n, dd;

int numPoints = 0;
priority_queue< pair<LD, bool> > Q;


void input(){
	scanf("%d%d", &n, &dd);
	
	Vector V = Vector(1,0);
	for(int i = 0; i < n; i++){
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		Circle C = Circle(Point(x,y), r);
		
		LD dst = Vector(x,y).length();
		int left = (int)ceil(dst-r);
		int right = (int)floor(dst+r);
		
		for(int d = (left+dd-1)/dd*dd; d <= right/dd*dd; d += dd){
			//printf("i=%d d=%d\n", i, d);
			Circle O = Circle(Point(), d);
			Point P1, P2;
			intersect(O, C, P1, P2);
			
			LD a1 = angle(V, Vector(P1)),
			   a2 = angle(V, Vector(P2));
			
			if(a1 > a2) swap(a1, a2);
			
			if(a2 - a1 > M_PI){
				swap(a1, a2);
				numPoints++;
			}
			
			//printf("a1=%Lf a2=%Lf\n", a1, a2);
			
			Q.push({-a1 + Eps*2, true});
			Q.push({-a2 - Eps*2, false});
		}
	}
}

int main(){
	input();
	
	int best = numPoints;
	while(!Q.empty()){
		//printf("%.12Lf %d\n", Q.top().first, Q.top().second);
		if(Q.top().second){
			numPoints++;
		} else {
			numPoints--;
		}
		Q.pop();
		
		best = max(best, numPoints);
	}
	printf("%d\n", best);
}