#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int T;
char a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",a+1);
		int len=strlen(a+1);
		int ok=0;
		for(int i=1;i<=len;i++){
			if(a[i]!='a'){
				printf("YES\n");
				ok=1;
				for(int v=1;v<=len-i+1;v++)printf("%c",a[v]);
				printf("a");
				for(int v=len-i+2;v<=len;v++)printf("%c",a[v]);
				printf("\n");
				break;
			}
		}
		if(ok==0){
			printf("NO\n");
		}
	}
	return 0;
}