#include<stdio.h>
#include<string.h>
int n,m;
char s[111][111];
int len[111];
int id[111];
char o[111];
bool process(){
	int L = len[id[1]];
	for(int i=1; i<=m; i++)
		if(len[id[i]] != L)
			return false;
	for(int i=0; i<L; i++){
		o[i] = s[id[1]][i];
		for(int j=1; j<=m; j++)
			if(o[i] != s[id[j]][i]){
				o[i] = '?';
				break;
			}
	}
	for(int i=1,j=1; i<=n; i++)
		if(j<=m && i == id[j])
			j++;
		else{
			bool ff = false;
			if(len[i] != L)continue;
			for(int k=0; k<L; k++){
				if(o[k]!='?' && o[k]!=s[i][k]){
					ff = true;
					break;
				}
			}
			if(!ff)
				return false;
		}
	puts("Yes");
	o[L]=0;
	puts(o);
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%s",s[i]);
		len[i] = strlen(s[i]);
	}
	for(int i=1; i<=m; i++){
		scanf("%d",&id[i]);
	}
	if(!process()){
		puts("No");
	}
	return 0;
}