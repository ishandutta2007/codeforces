#include <iostream>

using namespace std;

int n;
int a, b;
int A[12], B[12];

int main(void)
{
	cin >> n;
	cin >> a >> b;
	
	a--, b--;
	int N = -1;
	for(;n;n/=2) N++;
	
	int c = 0;
	for(int i = N-1; i >= 0; i--){
		if( (a & (1<<i)) != (b & (1<<i)) ) break;
		c++;
	}
	
	if(c == 0) cout << "Final!" << endl;
	else cout << N - c << endl;
	return 0;
}