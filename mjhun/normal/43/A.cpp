#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, r1=1, r2=0;
	bool b=true;
	char s1[20];
	char s2[20];
	char a[20];
	
	cin>>n;
	scanf("%s",s1);

	while(--n){
		scanf("%s",a);
		if(strcmp(a,s1)!=0){
			if(b){
				strcpy(s2,a);
				b=false;
			}
			r2++;
		}
		else
			r1++;
	}
	
	if(r1>r2)
		printf("%s\n",s1);
	else
		printf("%s\n",s2);
	
	return 0;
}