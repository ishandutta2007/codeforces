#include<cstdio>
#include<cstring>
const int N=1e5+5;
const int Z=26;
int Nxt[N][Z],T,len;
char s[N],t[N];
bool Vis[Z];
inline void Init(){
	memset(Nxt,-1,sizeof(Nxt));
	memset(Vis,0,sizeof(Vis));
	scanf("%s%s",s+1,t+1);
	len=strlen(s+1);
	for(register int i=1;i<=len;i++)
		Nxt[i-1][s[i]-'a']=i;
	for(register int i=len;i;i--){
		for(register int j=0;j<Z;j++)
			if(s[i+1]-'a'!=j) Nxt[i][j]=Nxt[i+1][j];
		Nxt[0][s[i]-'a']=i;
		Vis[s[i]-'a']=1;
	}
	return ;
}
inline void Query(){
	for(register int i=1;t[i];i++){
		if(!Vis[t[i]-'a']){
			puts("-1");
			return ;
		}
	}
	int p=0,ss=0;
	for(register int i=1;t[i];i++){
		int ch=t[i]-'a';
		if(Nxt[p][ch]!=-1) p=Nxt[p][ch];
		else{
			p=Nxt[0][ch];
			ss++;
		}
//		printf("%d ",p);
	}
//	putchar('\n');
	printf("%d\n",++ss);
	return ;
}
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Query();
	}
	return 0;
}