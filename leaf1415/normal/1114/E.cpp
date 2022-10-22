#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
vector<llint> vec;
llint a[1000005];

llint gcd(llint a, llint b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	cin >> n;
	llint res;
	
	srand(time(NULL));
	/*for(llint i = 0; i < n; i++) a[i] = i+1;
	random_shuffle(a, a+n);*/
	
	for(int i = 0; i < n; i++) a[i] = rand()*rand()%n+1;
	
	//for(llint i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	
	llint ub = 1000000000, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		cout << "> " << mid << endl;
		cin >> res;
		if(res) lb = mid;
		else ub = mid;
	}
	llint mx = lb+1;
	
	llint d = 0;
	for(llint i = 0; i < min(n, 30LL); i++){
		cout << "? " << a[i] << endl;
		cin >> res;
		d = gcd(d, mx-res);
	}
	llint x = mx - d*(n-1);
	cout << "! " << x << " " << d << endl;
	
	return 0;
}