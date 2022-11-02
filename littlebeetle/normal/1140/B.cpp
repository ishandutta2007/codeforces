#include<cstdio>
const int N=100002;
int T,n,a,b;
char s[N];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		a=1;
		while(s[a]!='>'&&a<=n)a++;
		b=n;
		while(s[b]!='<'&&b)b--;
		printf("%d\n",min(a-1,n-b));
	}
}