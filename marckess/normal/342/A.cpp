#include <iostream>

using namespace std;

int main(){
	int n, c[8] = {0}, x, part[3]={0};

	cin >> n;
	for (int i = 0; i < n ; i++){
		cin >> x;
		c[x] ++;
	}

	part[0] = min( c[1], min (c[2], c[4]) );
	c[1] -= part[0];
	c[2] -= part[0];
	c[4] -= part[0];

	part[1] = min( c[1], min(c[2], c[6]) );
	c[1] -= part[1];
	c[2] -= part[1];
	c[6] -= part[1];

	part[2] = min( c[1], min( c[3], c[6] ));

	if( part[0] + part[1] + part[2] != n / 3 )
		cout << -1;
	else{
		while(part[0]--)
			cout << "1 2 4 \n";
		while(part[1]--)
			cout << "1 2 6 \n";
		while(part[2]--)
			cout << "1 3 6 \n";
	}

	return 0;
}