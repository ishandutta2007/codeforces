/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN= 1000+5;

int n, k;

long double no_choose[MAXN], choose[MAXN];
long double prob[MAXN][MAXN];

inline long long check (unsigned long long e){
	long long r= 0;
	unsigned long long Pow= 1;
	while (Pow <= e){
		r+= min (Pow, e-Pow+1);
		Pow*= 10;
	}
	return r;
}
/****************************************/
int main (){
	cin >> n;
	for (int i= 1;i<= n;i ++){
		unsigned long long l, r;
		cin >> l >> r;
		choose[i]= ((long double)( check(r)-check(l-1) ))/(r-l+1);
		no_choose[i]= 1- choose[i];
	}
	prob[1][0]= 1;
	prob[1][1]= choose[1];
	for (int i= 2;i<= n;i ++)
		for (int j= 1;j<= i;j ++){
			prob[i][j]= no_choose[i]*prob[i-1][j]+ choose[i]*prob[i-1][j-1];
		prob[i][0]= 1;
	}
	cin >> k;
	k= (k*n+ 99)/100;

	cout << fixed << setprecision (9) << prob[n][k] << endl;	

	return 0;
}