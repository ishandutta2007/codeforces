#include<cstdio>
bool f[152];
int m=2847,n;
char s[101];
main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<n;++i){
		if(s[i]<97)s[i]+=32;
		if(!f[s[i]])
			f[s[i]]=true,m-=s[i];
	}
	puts(!m?"YES":"NO");
}