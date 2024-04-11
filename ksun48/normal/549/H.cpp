#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double r1;
double r2;
double mult(double a1, double a2, double b1, double b2){
	r2 = a2*b2;
	r1 = a2*b2;
	r2 = max(r2, a1*b2);
	r1 = min(r1, a1*b2);
	r2 = max(r2, a1*b1);
	r1 = min(r1, a1*b1);
	r2 = max(r2, a2*b1);
	r1 = min(r1, a2*b1);
	if((a1*a2 <= 0) || (b1*b2 <= 0)){
		r2 = max(r2, 0.0);
		r1 = min(r1, 0.0);

	}

}
int main(){

	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double s = 0;
	double e = 2000000000.0;
	for(int i = 0; i < 100; i++){
		double m = (s+e)/2;
		double q1, q2;
		mult(a-m,a+m,d-m,d+m);
		q1 = r1;
		q2 = r2;
		mult(b-m,b+m,c-m,c+m);
		//cout << m << " " << r1 << " " << r2 << " " << q1 << " " << q2 << endl;
		if(r1 > q2 || q1 > r2){
			s = m;
			continue;
		}
		e = m;
	}
	printf("%.10f\n", e);

}