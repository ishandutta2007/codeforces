#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;
typedef pair<int, int> PII;
const int N = 300005;
int n;
PII a[N], b[N];
int ta = 0, tb = 0;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		if(x < y) a[++ta] = make_pair(y, i);  
		else if(x > y) b[++tb] = make_pair(y, i);
	}
	if(ta >= tb){
		printf("%d\n", ta);
		sort(a + 1, a + 1 + ta);
		for(int i = ta; i; i--)
			printf("%d ", a[i].second);
	}else if(tb > ta){
		printf("%d\n", tb);
		sort(b + 1, b + 1 + tb);
		for(int i = 1; i <= tb; i++)
			printf("%d ", b[i].second);
	}
	puts("");
	return 0;
}