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
 */

#include <iostream>
#include <complex>

#define Complex complex <double> 
#define X real()
#define Y imag()

using namespace std;

const int MAXN= 100*1000+5;

int n, k;
Complex a[MAXN];

namespace std{
	inline double operator ^ (const Complex &fir, const Complex &sec){
		return (fir.X*sec.Y)- (fir.Y*sec.X);
	}
}
/***************************************/
inline bool tri_in (Complex &A, Complex &B, Complex &C, Complex &v){
	Complex G= (A+B+C);
	G.X/= 3, G.Y/= 3;
	if ((((B-A)^(v-B))*((B-A)^(G-B))) < 0)
		return false;
	if ((((C-B)^(v-C))*((C-B)^(G-C))) < 0)
		return false;
	if ((((A-C)^(v-A))*((A-C)^(G-A))) < 0)
		return false;
	return true;
}
/***************************************/
inline bool check_inside (Complex &v){
	int s= 1, e= n-1, r= -1;
	const Complex base= a[0]-v;
	while (s<= e){
		int mid= (s+e)/2;
		if ((base^(a[mid]-a[0]))>= 0){
			r= mid;
			e= mid-1;		
		}
		else
			s= mid+1;
	}
	if (r < 2)
		return false;
	return tri_in (a[0], a[r-1], a[r], v);
}
/**************************************/
int main (){
	cin >> n;
	for (int i= 0;i< n;i ++)
		cin >> a[i].X >> a[i].Y;
	cin >> k;
	for (int i= 1;i<= k;i ++){
		Complex p;
		cin >> p.X >> p.Y;
		if (!check_inside (p)){
			cout << 0 << endl;
			continue;
		}
		long long res= ((long long)n*(n-1)*(n-2))/6;
		int poi= 2;
		for (int j= 0;j< n;j ++){
			while (((a[j]-a[poi])^(p-a[j]))> 0)
				poi= (poi+1)%n;

			long long diff= ((poi > j) ? poi-j : poi+n-j)-1;
			res-= diff*(diff-1)/2;
		}
		cout << res << endl;
	}

	return 0;
}