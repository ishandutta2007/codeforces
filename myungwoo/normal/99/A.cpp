#include <stdio.h>
#include <string.h>

char buf[9999];

int main()
{
	int i,p;
	scanf("%s",buf+1); buf[0] = '0';
	for (p=1;buf[p]!='.';p++);
	if (buf[p-1] == '9') puts("GOTO Vasilisa.");
	else{
		if (buf[p+1] < '5') for (i=1;i<p;i++) printf("%c",buf[i]);
		else{
			buf[p-1]++;
			for (i=p-1;buf[i]>'9';i--) buf[i] = '0', buf[i-1]++;
			for (i=buf[0]-'0'?0:1;i<p;i++) printf("%c",buf[i]);
		}
	}
}