#include<cstdio>
const int N=1000004;
char s[N];
int n,cnt,i;
int main(){
	scanf("%s",s+2);
	n=2;
	while(s[n+1])n++;
	while(s[n-1]){
		cnt++;
		if(s[n]==49){
			for(i=n;s[i]==49;i--)
				s[i]=48;
			s[i]=49;
		}
		else
			n--;
	}
	printf("%d",cnt);
}