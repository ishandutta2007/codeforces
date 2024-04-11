#include<cstdio>
const int N=100020;
int n,i,k,cnt,kmp[N],f[N],x[N],y[N],ans;
char s[N];
void init(){
	scanf("%s",s);
	while(s[n])n++;
}
void work(){
	for(k=0,i=1;i<n;i++){
		while(k&&s[i]!=s[k])
			k=kmp[k];
		if(s[i]==s[k])
			kmp[i+1]=++k;
	}
	for(i=n;i;i--)
		f[kmp[i]]+=++f[i];
	for(i=n;i;i=kmp[i]){
		ans++;
		x[ans]=i;
		y[ans]=f[i];
	}
	printf("%d\n",ans);
	for(i=ans;i;i--)
		printf("%d %d\n",x[i],y[i]);
	//while(1);
}

int main(){
	init();
	work();
}