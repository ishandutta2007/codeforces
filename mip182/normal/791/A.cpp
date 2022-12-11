#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	double a,b,years;
	years=0;
	cin >> a>>b;
	while ( a*pow(3,years)<=b*pow(2,years))
	{
	    years=years+1;}
	    
	cout << years;
    
}