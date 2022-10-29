#include <iostream>
using namespace std;
int main() {
	int n,i;
	cin>>n;
	cout<<n<<' ';
	i=2;
	while(n!=1){
	if(n%i==0) {
		n = n/i;
		cout << n << ' ';
	}
	else ++i;
	}
	return 0;
}