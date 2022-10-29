#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char s1[105];
	char s2[105];
	int n,i;
	bool b;
	scanf("%s",s1);
	scanf("%s",s2);
	n=strlen(s1);
	b = strlen(s2)==n;
	for(i=0;b&&i<n;++i)
		b=s1[i]==s2[n-i-1];
	printf("%s\n",b?"YES":"NO");
	return 0;
}