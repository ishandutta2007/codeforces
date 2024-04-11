#include <cstdio>
#include <iostream>
#include <cstring> 
using namespace std;
const int N	= 100010;
int n;
char s[N];
int main(){
	scanf("%d%s", &n, s + 1);
	int round = (n - 11) >> 1;
	int cnt = 0; 
	for(int i = 1; i <= round && round <= n; i++){
		if(s[i] == '8')cnt++, round ++;
	}
	int i = round + 1;
	while(s[i] == '8' && i <= n) i++, cnt++;
	if(cnt > (n - 11) >> 1) puts("YES");
	else puts("NO");
	return 0;
}