#include<cstdio>
#include<cstring>
int w[30][30],ind[30];
char s[205];
bool ans;
char a[30];
int tot;
void Dfs(int u){
	a[tot++]=u+'a';
	if(ind[u]>1) ans=0;
	if(!ans) return ;
	ind[u]=-1;
	for(int i=0; i<26; i++)
		if(w[u][i]&&~ind[i]) ind[i]--,Dfs(i);
	return ;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		memset(w,0,sizeof(w));
		for(int i=0;s[i+1];i++)
			w[s[i]-'a'][s[i+1]-'a']=w[s[i+1]-'a'][s[i]-'a']=1;
		ans=1;
		for(int i=0; i<26; i++){
			ind[i]=0;
			for(int j=0; j<26; j++)
				if(w[i][j]) ind[i]++;
			if(w[i][i]) ans=0;
		}
		tot=0;
		for(int i=0; i<26; i++)
			if(ind[i]==1||ind[i]==0) Dfs(i);
		for(int i=0; i<26; i++)
			if(~ind[i]) ans=0;
		if(ans) puts("YES"),puts(a);
		else puts("NO");
	}
	return 0;
}