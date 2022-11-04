#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[1010];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf(" %s",s);
		int len = strlen(s);
		if(s[len-1] == 'o') puts("FILIPINO");
		if(s[len-1] == 'u') puts("JAPANESE");
		if(s[len-1] == 'a') puts("KOREAN");
	}
}