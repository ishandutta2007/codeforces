#include <cstdio>
#define MAXN 100005

int n, l, x, y, len[MAXN];

int test(int length){
	int l = 1, r = 1;
	while(1){
		while(len[r] - len[l] < length && r < n) ++ r;
		if(len[r] - len[l] == length) return l;
		if(len[r] - len[l] < length) return 0;
		while(len[r] - len[l] > length) l ++;
	}
	return 0;
}
int reverseTest(int length){
	int l = n, r = n;
	while(1){
		while(len[r] - len[l] < length && l) -- l;
		if(len[r] - len[l] == length) return r;
		if(len[r] - len[l] < length) return 0;
		while(len[r] - len[l] > length) -- r;
	}
	return 0;
}
int main(){
	int i, availDelta;
	scanf("%d%d%d%d", &n, &l, &x, &y);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &len[i]);
	int availX = test(x), availY = test(y);
	if(!(availX || availY)){
		availDelta = test(y - x);
		if(availDelta && len[availDelta] + y <= l){
			printf("1\n%d\n", len[availDelta] + y);
			return 0;
		}
		availDelta = test(x + y);
		if(availDelta){
			printf("1\n%d\n", len[availDelta] + x);
			return 0;
		}
		availDelta = reverseTest(y - x);
		if(availDelta && len[availDelta] - y >= 0){
			printf("1\n%d\n", len[availDelta] - y);
			return 0;
		}
		printf("2\n%d %d\n", x, y);
		return 0;
	}
	if(!availX)
		printf("1\n%d\n", x);
	else if(!availY)
		printf("1\n%d\n", y);
	else printf("0\n");
	return 0;
}