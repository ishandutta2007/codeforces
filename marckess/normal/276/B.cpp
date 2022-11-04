#include <stdio.h>

using namespace std;

int main(){
	int n = 'z' - 'a' + 1;
	int l[n] = {0};
	char c;

	while ( scanf( "%c ", &c ) == 1 )
		l[c-'a']++;

	int impar = 0;

	for (int i = 0; i < n; i++)
		if ( l[i] % 2 )
			impar ++;

	if ( impar < 2 || impar % 2 )
		printf("First\n");
	else
		printf("Second\n");

	return 0;
}