#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s[405],ans;
char ch[405][25];
bool used[405];
char now[405];
bool same(int i,int j){
	if(s[i]!=s[j]) return 0;
	for(int k=1;k<=s[i];++k) if(ch[i][k]!=ch[j][k]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",now);int len=strlen(now);
		for(int j=0;j<len;j++){
			if(now[j]=='h'){
				while(s[i]>0&&ch[i][s[i]]=='k')ch[i][s[i]]=0,s[i]--;
				ch[i][++s[i]]='h';
			}
			else if(now[j]=='u')ch[i][++s[i]]='o',ch[i][++s[i]]='o';
			else ch[i][++s[i]]=now[j];
		}
//		printf("%s",ch[i]+1);
	}
	for(int i=1;i<=n;i++)if(!used[i]){
		used[i]=1;ans++;
		for(int j=1;j<=n;j++){
			if(i!=j&&!used[j]){
				if(same(i,j)) used[j]=1;
			}
		}
	}printf("%d\n",ans);
	return 0;
}