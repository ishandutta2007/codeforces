#include<cstdio>
const int N=400002;
char s[N],c;
int n,i;
int main(){
	scanf("%s",s+1);
	for(i=2;s[i];i++){
		if(s[i]==s[i-1]){
			c='a';
			while(c==s[i-1]||c==s[i+1])
				c++;
			s[i]=c;
		}
	}
	printf("%s",s+1);
}