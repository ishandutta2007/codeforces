#include <iostream>
#define llint long long

using namespace std;

int T;
int a, b;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> a >> b;
		if(gcd(a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	
	return 0;
}