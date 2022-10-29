#include <iostream>
using namespace std;

int main() {
	unsigned int n, r, s;
	
	cin >> n;
	s=0;
	for(unsigned int i=0; i<n; ++i) {
		cin>>r;
		s+=r;
	}
	r = 0;
	s--;
	for(unsigned int i=1;i<=5;++i) {
		r += ((s+i)%(n+1))!=0;
	}
	
	cout << r << endl;
	
	return 0;
}