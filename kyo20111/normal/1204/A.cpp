#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[111];
int len;
int f(){
	if(len%2 == 0) return 0;
	for(int i=1;i<len;i++) if(s[i] != '0') return 0;
	return 1;
}
int main(){
    scanf("%s",s);
    len = strlen(s);
    printf("%d",(len+1)/2 - f());
}