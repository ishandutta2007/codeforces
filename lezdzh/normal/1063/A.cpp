#include<cstdio>

using namespace std;

char s[100010];
int a[233];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;s[i];i++)
		a[s[i]]++;
	for(int i=1;i<=232;i++)
		for(int j=1;j<=a[i];j++)
			printf("%c",i);
}