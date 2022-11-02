#include<cstdio>
const int N=200002;
char s[N];
int n,i,f;
int main(){
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++){
		if(s[i]>s[i+1]&&!f)
			f=1;
		else
			printf("%c",s[i]);
	}
	return 0;
}