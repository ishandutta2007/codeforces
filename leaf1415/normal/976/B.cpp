#include <iostream>
#define llint long long

using namespace std;

llint n, m, k;

int main(void)
{
	cin >> n >> m >> k;
	
	if(k <= n-1){
		cout << k+1 << " " << 1 << endl;
		return 0;
	}
	
	llint dan = (k-n)/(m-1), off = (k-n)%(m-1);
	llint ansR = n - dan, ansC;
	
	if(dan % 2){
		ansC = m - off;
	}
	else{
		ansC = 2 + off;
	}
	
	cout << ansR << " " << ansC << endl;
	return 0;
}