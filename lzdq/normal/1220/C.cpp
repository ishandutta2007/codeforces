#include<cstdio>
const int Z=26;
const int N=5e5+5;
bool Vis[Z];
char s[N];
inline void Check(const int k){
	for(register int i=(int)s[k]-97-1;i>=0;i--)
		if(Vis[i]){
			puts("Ann");
			return ;
		}
	puts("Mike");
}
inline void Query(){
	for(register int i=0;s[i];i++){
		Check(i);
		int x=(int)s[i]-97;
		Vis[x]=1;
	}
}
int main(){
	scanf("%s",s);
	Query();
	return 0;
}