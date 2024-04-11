#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct fraction{
	int64 num, den;

	fraction(int64 n=0, int64 d=1) : num(n), den(d) {
		fix();
	}

	void fix(){
		if (den < 0){
			num *= -1;
			den *= -1;
		}

		int64 g = __gcd( abs(num), den );
		num /= g;
		den /= g;
	}

	fraction operator+( const fraction &f ) const{
		return fraction( num * f.den + f.num * den, den * f.den);
	}

	fraction operator-( const fraction &f ) const{
		return fraction( num * f.den - f.num * den, den * f.den);
	}

	fraction operator*( const fraction &f) const{
		return fraction( num * f.num, den * f.den );
	}

	fraction operator/( const fraction &f) const{
		return fraction( num * f.den, den * f.num );
	}

	bool operator<( const fraction &f ) const{
		return num * f.den < f.num * den;
	}

	bool operator<=(const fraction &f ) const{
		return !( f < *this );
	}

	void print(){
		cout << 1. * num / den << endl;
	}
};

void no(){
	cout << -1 << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	fraction A(-1), B(1000000000);

	int n; cin >> n;

	int64 x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	for (int i = 0; i < n; ++i){
		int64 rx, ry, vx, vy;
		
		cin >> rx >> ry >> vx >> vy;

		fraction a(1000000000), b(-1);

		if (x1 < rx && rx < x2 && y1 < ry && ry < y2){
			a = fraction();
			if (vx == 0 && vy == 0)
				continue;
		}

		if (vx != 0){
			for (auto xx : {x1, x2}){
				fraction k = ( fraction(xx) - fraction(rx) ) / fraction( vx );
				fraction y = fraction(ry) + k * fraction( vy );

				if (fraction(y1) <= y && y <= fraction(y2))
				{
					a = min(a, k);
					b = max(b, k);
				}
			}
		}
		else{
			if (rx <= x1 || rx >= x2) no();
		}

		if (vy != 0){
			for (auto yy : {y1, y2}){
				fraction k = ( fraction(yy) - fraction(ry) ) / fraction( vy );
				fraction x = fraction(rx) + k * fraction( vx );

				if (fraction(x1) <= x && x <= fraction(x2))
				{
					a = min(a, k);
					b = max(b, k);
				}
			}
		}
		else{
			if (ry <= y1 || ry >= y2) 
				no();
		}

		if (a < fraction(0)) a = fraction();
		if (b < fraction(0)) b = fraction();

		A = max(A, a);
		B = min(B, b);

		// A.print();
		// B.print();

		if ( !(A < B) )
			no();
	}

	if (A < fraction(0)) A = fraction();	
	double answer = 1. * A.num / A.den;

	cout.precision(10);
	cout << answer << endl;

	return 0;
}