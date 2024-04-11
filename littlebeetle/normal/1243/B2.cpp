#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=202;
char s[N],t[N];
int cnt[N],T,n,tmp;
int m,x[N],y[N],i,j;
void init(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d%s%s",&n,s+1,t+1);
}
void work(){
	tmp=1;
	for(i=1;i<=n;i++){
		cnt[s[i]]++;
		cnt[t[i]]++;
	}
	for(i=0;i<N;i++)
		if(cnt[i]&1)
			tmp=0;
	if(tmp==0){
		printf("No\n");
		return;
	}
	printf("Yes\n");
	m=0;
	for(i=1;i<=n;i++)
		if(s[i]!=t[i])
			for(j=i+1;j<=n;j++){
				if(s[j]==s[i]){
					m++;
					x[m]=j;y[m]=i;
					swap(s[j],t[i]);
					break;
				}
				if(t[j]==s[i]){
					m++;
					x[m]=j;y[m]=j;
					swap(s[j],t[j]);
					m++;
					x[m]=j;y[m]=i;
					swap(s[j],t[i]);
					break;					
				}
			}
	printf("%d\n",m);
	for(i=1;i<=m;i++)
		printf("%d %d\n",x[i],y[i]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	return 0;
}