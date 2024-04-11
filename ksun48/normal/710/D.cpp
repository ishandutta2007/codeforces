#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){
	return ((b == 0) ? a : gcd(b,a%b));
}
LL modInverse(LL a, LL m)
{
    LL m0 = m, t, q;
    LL x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

int main(){
	LL a1, b1, a2, b2, l, r;
	cin >> a1 >> b1 >> a2 >> b2 >> l >> r;

	if(b1 < b2){
		swap(a1,a2);
		swap(b1,b2);
	}
	LL c = gcd(a1,a2);
	if((b1-b2) % c != 0){
		cout << 0 << endl;
		return 0;
	}
	b2 -= b1;
	l -= b1;
	r -= b1;
	b2 /= c;
	a1 /= c;
	a2 /= c;
	if(l < 0) l = 0;
	if(r < 0){
		cout << 0 << endl;
		return 0;
	}
	r /= c;
	l += (c-1);
	l /= c;


	LL d = modInverse(a1,a2);
	d *= b2;
	d %= a2;
	while(d < 0) d += a2;

	r /= a1;
	l += (a1-1);
	l /= a1;


	l -= d;
	r -= d;
	if(l < 0) l = 0;
	if(r < l){
		cout << 0 << endl;
		return 0;
	}
	r /= a2;
	l += (a2-1);
	l /= a2;
	cout << max(0LL,r-l+1) << endl;
}