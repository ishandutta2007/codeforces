#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char s1[105];
	char s2[105];
	scanf("%s",s1);
	scanf("%s",s2);
	for(int i=0;i<strlen(s1);++i)
		printf("%d",s1[i]!=s2[i]);
	return 0;
}