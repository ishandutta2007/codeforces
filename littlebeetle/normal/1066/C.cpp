#include<cstdio>
const int N=400002;
int p,a[N],l,r,n;
char s[3];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	l=200000;
	r=199999;
	scanf("%d",&n);
	while(n--){
		scanf("%s%d",s,&p);
		if(*s=='L')a[p]=--l;
		if(*s=='R')a[p]=++r;
		if(*s=='?')printf("%d\n",min(r-a[p],a[p]-l));		
	}
}