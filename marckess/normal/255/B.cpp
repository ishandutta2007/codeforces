#include <bits/stdc++.h>

using namespace std;

int main(){
	int x=0,y=0;
	char c;

	while( scanf("%c", &c) == 1 ){
		if ( c == 'x' )
			x++;
		if ( c == 'y' )
			y++;
	}

	if ( x > y ){
		x -= y;
		while(x--)
			cout << 'x';
	}else{
		y -=x;
		while(y--)
			cout << 'y';
	}


	return 0;
}