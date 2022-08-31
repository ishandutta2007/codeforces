#include<iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	int i = 0;
	int s = 0;
	int p = 0;
	while (p <= x){
		++i;
		s += i;
		p += s;
	}
	cout << i - 1 << endl;
	return 0;
}