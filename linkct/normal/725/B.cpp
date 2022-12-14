#include <cstdio>
typedef long long int LL;
const int res[6] = {4, 5, 6, 3, 2, 1};

int main(){
	int i; char pos, buf[105]; LL n;
	scanf("%s", buf);
	for(i = 0; buf[i]; ++ i) ;
	pos = buf[-- i]; buf[i] = 0;
	sscanf(buf, "%I64d", &n);
	printf("%I64d\n", ((n - 1) / 4) * 16 + (1 - (n & 1)) * 7 + res[pos - 'a']);
	return 0;
}