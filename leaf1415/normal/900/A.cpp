#include <iostream>

using namespace std;

int n;
int pcnt, ncnt;

int main(void)
{
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		if(x < 0) ncnt++;
		if(x > 0) pcnt++;
	}
	
	if(pcnt <= 1 || ncnt <= 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}