#include <cstdio>
#include <iostream>
using namespace std;
const int N = 300010;
int n;
char s[N];
int main(){
	scanf("%d%s", &n, s + 1);
	int maxn = s[1], k = 1;
	for(int i = 2; i <= n; i++){
		if(s[i] < maxn){
			printf("YES\n%d %d\n", k, i);
			return 0;
		}
		if(s[i] > maxn){
			maxn = s[i];
			k = i;
		}
	}
	printf("NO\n");
	return 0;
}