#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
const int N = 10005;
char str[N], s1[N], s2[N], s3[N], ans[N];
bitset<N> a[3][26], now; 
int n;
int main(){
	scanf("%s", str);
	n = strlen(str);
	 for (int i = 0; i< n; ++i) {
        int t = i;
        s1[i] = 'a' + t % 26; t /= 26;
        s2[i] = 'a' + t % 26; t /= 26;
        s3[i] = 'a' + t % 26; t /= 26;
    }	
	printf("? "); puts(s1); fflush(stdout); scanf("%s", s1);
    printf("? "); puts(s2); fflush(stdout); scanf("%s", s2);
    printf("? "); puts(s3); fflush(stdout); scanf("%s", s3);
	
	for (int i = 0; i < n; ++i) a[0][s1[i] - 'a'].set(i);
    for (int i = 0; i < n; ++i) a[1][s2[i] - 'a'].set(i);
    for (int i = 0; i < n; ++i) a[2][s3[i] - 'a'].set(i);
    
	
	for (int i = 0; i < n; ++i) {
        int t = i;
        now = a[0][t % 26]; t /= 26;
        now &= a[1][t % 26]; t /= 26;
        now &= a[2][t % 26]; t /= 26;
        for (int j = 0; j < n; ++j) 
            if (now[j]) { ans[i] = str[j]; break; }
    }
	printf("! %s\n", ans);
	return 0;
}