#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[10101],t[10101];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s %s",s+1,t+1);
		int fl = 0, fl2 = 0, fl3 = 0;
		for(int i=1;i<=n;i++){
			if(s[i] != t[i]){
				if(fl){
					if(!fl3 && s[i] == fl && t[i] == fl2){
						fl3 = 1;
					}else{
						fl3 = 0;
						break;
					}
				}else{
					fl = s[i];
					fl2 = t[i];
				}
			}
		}
		printf("%s\n",fl3?"Yes":"No");
	}
}