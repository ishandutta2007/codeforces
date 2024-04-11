#include<cstdio>
const int N=3e5+5;
int num[2][N];
char s[N];
inline void Init(){
	num[0][0]=num[1][0]=0;
	scanf("%s",s);
	for(int i=0;s[i];i++){
		int p=s[i]-48;
		num[p&1][++num[p&1][0]]=p;
	}
}
inline void Query(){
	int p=1;
	for(int i=1;i<=num[0][0];i++){
		while(p<=num[1][0]&&num[1][p]<num[0][i])
			putchar(num[1][p++]+48);
		putchar(num[0][i]+48);
	}
	while(p<=num[1][0]) putchar(num[1][p++]+48);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		Init();
		Query();
	}
	return 0;
}