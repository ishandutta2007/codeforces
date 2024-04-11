#include<bits/stdc++.h>
using namespace std;
const int N=110;
int T;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(s[1]!=s[n]){
			s[n]=s[1];
		}
		printf("%s\n",s+1);
	}
	return 0;
}