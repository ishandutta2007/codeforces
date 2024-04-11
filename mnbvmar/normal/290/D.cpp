#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

char str[60];
int t;

int main(){
	scanf("%s%d", str, &t);
	for(char *c = str; *c; c++){
		*c |= 32;
		if(*c < t+97) *c ^= 32;
	}
	printf("%s\n", str);
}