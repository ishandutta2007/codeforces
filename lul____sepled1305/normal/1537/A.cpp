#include <iostream>
using namespace std;
 
int main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		int sum = 0;
		for(int i=0;i<n;i++) {
			int a; cin>>a; sum += a;
		}
		if(sum == n)
			cout<<"0\n";
		else
			cout<<max(1,sum-n)<<endl;
	}
	return 0;
}