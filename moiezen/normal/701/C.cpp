#include <cstdio>
#include <cstring>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 100005
char str[N];
int ch[233],cont;
int n,l,r,nw,ans;
void mvl(){
	if(!--ch[str[l++]]) nw--;
}
void mvr(){
	if(!ch[str[++r]]++) nw++;
}
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	memset(ch,0,sizeof(ch));
	cont=0;
	rpt(i,1,n) if(!ch[str[i]]) ch[str[i]]=1,cont++;
	memset(ch,0,sizeof(ch));
	l=1;r=0;nw=0;ans=1<<30;
	rpt(i,1,n){
		while(nw<cont&&r<n) mvr();
		if(nw>=cont&&r-l+1<ans) ans=r-l+1;
		mvl();
	}
	printf("%d",ans);
}