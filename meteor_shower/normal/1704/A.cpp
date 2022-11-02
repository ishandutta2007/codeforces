#include<cstdio>
const int N=55;
char a[N],b[N];
int n,m;
inline bool Check(){
	for(int i=1;i<m;i++)
		if(a[n-i+1]!=b[m-i+1]) return 0;
	for(int i=n-m+1;i;i--)
		if(a[i]==b[1]) return 1;
	return 0;
}
int T;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d %d",&n,&m);
		scanf("%s",a+1);
		scanf("%s",b+1);
		if(Check()) puts("Yes");
		else puts("No");
	}
	return 0;
}