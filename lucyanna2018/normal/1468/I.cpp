#include<iostream>
#include<cstdio>
using namespace std;
#define i64 long long int
i64 gcd(i64 X, i64 Y){return Y?gcd(Y,X%Y):X;}
i64 lcm(i64 X, i64 Y){return X/gcd(X,Y)*Y;}
i64 AB(i64 X) {return X > 0?X:-X;}
int main(){
	i64 A,B,C,D,N;
	cin >> N >> A >> B >> C >> D;
	i64 delta = A*D-B*C;
	if (N != AB(delta)) { puts("NO"); return 0; }
	puts("YES");
	i64 X = lcm(N / gcd(N, AB(D)), N / gcd(N, AB(B)));
	for(int i=0; i<X; i++)for(int j=0; j<N/X; j++)
		printf("%d %d\n",i,j);
	return 0;
}