#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n;

int main(void)
{
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a != 0) s.insert(a);
	}
	cout << s.size() << endl;
	return 0;
}