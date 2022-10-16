#include <bits/stdc++.h>

using namespace std;

//#define int long long

typedef long long LL;

struct Point {
	int x, y;

	Point operator+(const Point other) const {
		return Point{x+other.x, y+other.y};
	}
	Point operator-(const Point other) const {
		return Point{x-other.x, y-other.y};
	}
	int dist() const {
		return x*x + y*y;
	}

	int cross_prod(const Point other) const {
		return x * other.y - y * other.x;
	}
	int dot_prod(const Point other) const {
		return x * other.x + y * other.y;
	}
};

int check_circle(const Point O, const Point P, const int r2){
	int dst = (P-O).dist();
//	dst *= dst;
	if(dst < r2) return -1;
	else if(dst == r2) return 0;
	else return 1;
}

const int MaxPol = 1005;

int N, M;
Point A[MaxPol], B[MaxPol];
Point RA, RB;

void input(){
	int x, y;
	cin >> x >> y;
//	scanf("%lld%lld", &x, &y);
	RA = Point{x, y};
	cin >> N;
//	scanf("%lld", &N);
	for(int i = 0; i < N; i++){
		cin >> x >> y;
//		int x, y;
//		scanf("%lld%lld", &x, &y);
		A[i] = Point{x, y};
	}

	cin >> x >> y;
//	scanf("%lld%lld", &x, &y);
	RB = Point{x, y};
	cin >> M;
//	scanf("%lld", &M);
	for(int i = 0; i < M; i++){
		cin >> x >> y;
//		int x, y;
//		scanf("%lld%lld", &x, &y);
		B[i] = Point{x, y};
	}
}


bool checkout(int numA, int numB, Point* PA, Point* PB, Point OA, Point OB){
	int radius2 = (OA-OB).dist();
	for(int b = 0; b < numB; b++){
		Point relative = PB[b] + OA - OB;
//		printf("b=%d rel=(%d,%d)\n", b, relative.x, relative.y);
//		int ap1 = (a+1) % numA;

		for(int a = 0; a < numA; a++){
			int anext = (a+1) % numA;
//			int radius2 = (OA-OB).dist();

			int sgn1 = check_circle(relative, PA[a], radius2),
		        sgn2 = check_circle(relative, PA[anext], radius2);

//			printf("%d %d %d %d\n", b, a, sgn1, sgn2);
			if(sgn1 == 0 || sgn2 == 0) return true;
			if(sgn1 * sgn2 == -1) return true;
			if(sgn1 == 1 && sgn2 == 1){
				int dst = (PA[anext]-PA[a]).dist();
				// odl = cprod / dst
				int cprod = (PA[anext]-PA[a]).cross_prod(relative-PA[a]);
				int proj_len = (PA[anext]-PA[a]).dot_prod(relative-PA[a]);
//				printf("dst=%d cprod=%d proj_len=%d\n", dst, cprod, proj_len);
				if((LL)cprod*cprod <= (LL)radius2 * dst
						&& proj_len >= 0 && (LL)proj_len <= (LL)dst){
					return true;
					
				}
			}
		}
	}
	return false;
}

bool checkout(){
	return checkout(N, M, A, B, RA, RB) || checkout(M, N, B, A, RB, RA);
}


main(){
	input();

	printf(checkout() ? "YES\n" : "NO\n");
}