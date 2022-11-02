#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=1000020;
int n,m,i,j,a[N],L,R;
int s[N],S[N],cnt,x,Ans;
void init(){
	scanf("%d%d",&n,&m);
	m=m*8/n;
	if(m>22){
		printf("0");
		exit(0);
	}
	m=1<<m;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
}
void work(){
	for(i=1;i<=n;i++){
		for(j=i;a[i]==a[j+1];j++);
		s[++cnt]=j-i+1;
		i=j;
		S[cnt]=S[cnt-1]+s[cnt];
	}
	if(cnt<=m){
		printf("0");
		return;
	}
	Ans=1<<30;
	for(i=0;i+m<=cnt;i++)
		Ans=min(Ans,S[i]-S[0]+S[cnt]-S[i+m]);
	printf("%d",Ans);
	
}
int main(){
	init();
	work();
	return 0;
}