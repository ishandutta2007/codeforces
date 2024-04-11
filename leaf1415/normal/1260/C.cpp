#include <iostream>
#define llint long long

using namespace std;

llint T;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	llint r, b, k;
	for(int t = 0; t < T; t++){
		cin >> r >> b >> k;
		if(r == b){
			cout << "OBEY" << endl;
			continue;
		}
		if(r > b) swap(r, b);
		llint lcm = r * b / gcd(r, b);
		llint R = lcm/r-1, B = lcm/b;
		if(k <= (R+B-1)/B)  cout << "REBEL" << endl;
		else  cout << "OBEY" << endl;
	}
	return 0;
}