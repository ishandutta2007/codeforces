#include <cstdio>
#include <cmath>
#include <algorithm>
using std :: sort;
const double eps = 1e-8;

int n;
double p[105];

double get(double x){return x / (1.0 - x);}
int main(){
	int i; double p_ = 1.000, s_ = 0.000;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i) scanf("%lf", &p[i]);
	sort(p + 1, p + 1 + n);
	if(fabs(p[n] - 1.00) <= eps){
		printf("%.15f\n", 1.0);
		return 0;
	}
	for(i = n; i; -- i){
		s_ += p[i] / (1.0 - p[i]);
		p_ *= (1.0 - p[i]);
		if(s_ > 1) break;
	}
	printf("%.15f\n", s_ * p_);
	return 0;
}