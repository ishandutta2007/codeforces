#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
int n;char tmp[25];
int len[405];char s[405][45];
int ok(int x,int y){
	if(len[x]!=len[y]) return 0;
	rep(i,1,len[x]) if(s[x][i]!=s[y][i]) return 0;
	return 1;
} 
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",tmp+1);
		int l=strlen(tmp+1);
		per(j,l,1) if(tmp[j]=='u') s[i][++len[i]]='o',s[i][++len[i]]='o';
		else if(tmp[j]=='k'&&len[i]&&s[i][len[i]]=='h');
		else s[i][++len[i]]=tmp[j];
	}
	int ans=0;
	rep(i,1,n){
		int tag=1;
		rep(j,1,i-1) if(ok(i,j)){
			tag=0;break;
		}
		if(tag) ans++;
	}
	printf("%d\n",ans);
}