#include <iostream>
#include <set>
#include <map>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	int* v = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> v[i]; v[i]--;
	}
 
	for (int i = 0; i < n; i++) {
	    map <int,int> m;
	    int tmp;
		tmp = i;
		while (m[v[tmp]]!=1) {
			m[tmp]++;
			tmp=v[tmp];
		}
		cout << v[tmp] + 1 << endl;
	}
	//system("PAUSE");
}