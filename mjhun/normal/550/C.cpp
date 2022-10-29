#include <bits/stdc++.h>
using namespace std;

char s[128];
int n;

int main(){
	scanf("%s",s+2);
	n=strlen(s+2)+2;
	for(int i=2;i<n;++i)s[i]-='0';
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){	
			for(int k=j+1;k<n;++k){
				int q=s[i]*100+s[j]*10+s[k];
				if(q%8==0){printf("YES\n%d\n",q);return 0;}
			}
		}
	}
	puts("NO");
	return 0;
}