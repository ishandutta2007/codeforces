#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
double rate;

int main(void)
{
	cin >> n >> m;
	
	rate = 1e10;
	double a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		rate = min(rate, a/b);
	}
	
	printf("%.10f\n", rate * m);
	return 0;
}