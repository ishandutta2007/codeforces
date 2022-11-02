#include<cstdio>
#include<cstring>
using namespace std;
const int N=1002;
int T,n,i,j,k,p[N];
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		memset(p,0,sizeof(p));
		for(i=1;s[i];i++)
			if(s[i]==s[i+1])
				i++;
			else
				p[s[i]]=1;
		for(i=0;i<N;i++)
			if(p[i])
				printf("%c",i);
		printf("\n");
	}
}