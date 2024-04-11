#include<cstdio>
const int N=200002;
char s[N];
int n,f[3],S;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%s",s+1);
	f[1]=f[2]=-N;
	while(s[n+1]){
		n++;
		s[n]-=48;
		S+=s[n];
		S%=3;
		f[S]=max(f[S]+1,max(f[(S+1)%3],f[(S+2)%3]));
	}
	printf("%d\n",max(f[0],max(f[1],f[2])));
	return 0;
}