#include <stdio.h>
#define llint long long

using namespace std;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint n;

int main(void)
{
	scanf("%I64d", &n); //cin >> n;
	llint p, q, b;
	for(int i = 0; i < n; i++){
		scanf("%I64d %I64d %I64d", &p, &q, &b);
		//cin >> p >> q >> b;
		llint d;
		d = gcd(p, q);
		p /= d, q /= d;
		while(1){
			d = gcd(q, b);
			if(d == 1) break;
			while(q % d == 0) q /= d;
		}
		if(q == 1) printf("Finite\n"); //cout << "Finite" << endl;
		else printf("Infinite\n"); //cout << "Infinite" << endl;
	}
	return 0;
}