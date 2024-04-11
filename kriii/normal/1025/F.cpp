#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N,X[2020],Y[2020];

long long ccw(long long c, long long d, long long e, long long f)
{
	return c * f - e * d;
}

struct pt{
	pt(){}
	pt(int x_, int y_){
		x = x_; y = y_;
		if (y > 0) t = 0;
		else if (y < 0) t = 1;
		else if (x > 0) t = 0;
		else t = 1;
	}
	long long x,y; int t;

	bool operator <(const pt &v)const{
		if (t != v.t) return t < v.t;
		return ccw(x,y,v.x,v.y) > 0;
	}
}P[4040];

long double pi = acos(-1.0);

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%d %d",&X[i],&Y[i]);

	long long ans = 0;
	for (int v=0;v<N;v++){
		int c = 0;
		for (int j=0;j<N;j++) if (j != v) P[c++] = pt(X[j]-X[v],Y[j]-Y[v]);
		sort(P,P+c);

		for (int i=0;i<c;i++) P[i+c] = P[i];

		int B = 0;
		for (int i=0,j=0;i<c;i++){
			while (i == j || ccw(P[i].x,P[i].y,P[j].x,P[j].y) > 0) B++, j++;
			B--;
			long long p = B * (B - 1) / 2;
			int R = N - B - 2;
			long long q = R * (R - 1) / 2;
			ans += (long long)p * q;
		}
	}
	printf ("%lld\n",ans/2);

	return 0;
}