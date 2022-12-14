#include <cstdio>
const int MAXN = 100005;

char str[MAXN], s[MAXN];
int top;

int main(){
	int i;
	scanf("%s", str + 1);
	for(i = 1; str[i]; ++ i)
		if(!top) s[++ top] = str[i];
		else if(s[top] == str[i]) top --;
		else s[++ top] = str[i];
	printf("%s\n", top ? "No" : "Yes");
	return 0;
}