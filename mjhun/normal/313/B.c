#include <stdio.h>
#include <string.h>

#define MAX_ELEM 100010

int main() {
	char string[MAX_ELEM];
	
	scanf("%s", string);
	
	unsigned int n = strlen(string), count=0;
	unsigned int queries[n];
	unsigned int i;
	
	for(i = 0; i<n; i++) {
		queries[i] = count;
		count += string[i] == string[i+1];
	}
	unsigned int l, r, m;
	scanf("%u", &m);
	for(i=0;i<m;i++) {
		scanf("%u %u", &l, &r);
		printf("%u\n", queries[r-1] - queries[l-1]);
	}
	return 0;
}