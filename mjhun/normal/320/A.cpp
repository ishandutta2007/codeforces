#include <iostream>
using namespace std;
int main() {
	int k=0;
	bool r=true;
	char c;
	while(cin >> c) {
		if(c=='1')
			k=1;
		else if(c=='4') {
			if(k==0)
				r=false;
			else if(k<3)
				k++;
			else
				r=false;
		}
		else
			r=false;
	}
	cout << (r?"YES":"NO") << endl;
	return 0;
}