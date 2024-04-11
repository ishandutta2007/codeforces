#include <iostream>

using namespace std;

int main(){
	int n, a[500005];
	cin >> n;

	a[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int max1 = 0, min2 = 1000000000, max2 = 0, min3 = min2;
	bool f = true;
	int a2, b2;

	//Analiza el primer segmento maximo
	int i = 0;
	while ( i < n && a[i] <= a[i+1] ){
		max1 = a[i];
		i++;
	}

	//Segundo segmento (invertido)
	a2 = b2 = i;
	max2 = a[i];
	while ( i < n && a[i] > a[i+1] ){
		i++;
		min2 = a[i];
		b2 = i;
	} 

	//Tercer segmento
	if ( i != n )
		min3 = a[i+1];
	while ( i < n && a[i] <= a[i+1])
		i++;

	if ( i == n && min2 >= max1 && max2 <= min3)
		cout << "yes\n" << a2 << " " << b2;
	else
		cout << "no";

	return 0;
}