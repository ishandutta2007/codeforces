#include <iostream>

using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int Misha = max(3*a/10, a-a/250*c);
	int Vasya = max(3*b/10, b-b/250*d);

	if (Misha == Vasya)
		cout << "Tie";
	else if ( Misha > Vasya) 
		cout << "Misha";
	else
		cout << "Vasya";
}