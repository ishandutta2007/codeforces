#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint m12, m34, m23, m45;

int main(void)
{
	cout << "? 1 2" << endl;
	cin >> m12;
	cout << "? 3 4" << endl;
	cin >> m34;
	cout << "? 2 3" << endl;
	cin >> m23;
	cout << "? 4 5" << endl;
	cin >> m45;
	
	llint p[] = {4, 8, 15, 16, 23, 42};
	do{
		if(p[0]*p[1] == m12 && p[2]*p[3] == m34 && p[1]*p[2] == m23 && p[3]*p[4] == m45){
			cout << "!";
			for(int i = 0; i < 6; i++) cout << " " << p[i];
			cout << endl;
			return 0;
		}
	}while(next_permutation(p, p+6));
	return 0;
}