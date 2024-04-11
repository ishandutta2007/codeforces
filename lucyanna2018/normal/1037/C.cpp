#include<cstdio>

#define ran 1001001

int len;
char a[ran], b[ran];
bool f[ran];

int main() {
	scanf("%d%s%s", &len, a, b);
	
	for(int i=0;i<len;i++)
		f[i] = (a[i]!=b[i]);
	
	int ans=0;
	for(int i=0;i<len;) {
		if (i<len-1 && f[i] && f[i+1] && a[i]!=a[i+1]) {
			ans++;
			i+=2;
		} else
		if (f[i]) {
			ans++;
			i+=1;
		} else {
			i+=1;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}