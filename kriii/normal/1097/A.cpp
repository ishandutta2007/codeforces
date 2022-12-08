#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

char S[10],T[10];

int main()
{
	scanf ("%s",S);
	for (int k=0;k<5;k++){
		scanf ("%s",T);
		if (S[0] == T[0] || S[1] == T[1]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}