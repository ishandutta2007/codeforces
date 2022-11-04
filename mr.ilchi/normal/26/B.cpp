/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int maxN= 1000*1000 + 5;

char s[maxN];

int main(){
	gets (s);
	int bal= 0, open=0;
	for (int i=0; s[i];i ++){
		if (s[i]=='('){
			open ++; bal++;
		}

		else{
			if (bal > 0)
				bal --;
		}
	}
	printf ("%d\n", 2*(open-bal));
	return 0;
}