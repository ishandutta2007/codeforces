#include<cstdio>
#include<cstring>
const int MAXN=2e5+5;
int n,q;
char s[MAXN];
int rsum[MAXN][26];
bool Calc(int l,int r){
	int ind=0;
	for(int i=0; i<26; i++){
		if(rsum[r][i]>rsum[l-1][i]){
			ind++;
		}
	}
	if(ind>2||ind==2&&s[l]!=s[r]||l==r) return 1;
	return 0;
	if(l==r) return 1;
	if(s[l]!=s[r]) return 1;
	int c=s[l]-'a';
	if(rsum[r][c]-rsum[l-1][c]==r-l+1) return 0;
	int w=-1;
	if(w!=-1&&rsum[r][w]-rsum[l-1][w]==1||rsum[r][c]-rsum[l-1][c]==2) return 0;
	return 1;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; i++){
		for(int j=0; j<26; j++)
			rsum[i][j]=rsum[i-1][j];
		rsum[i][s[i]-'a']++;
	}
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(Calc(l,r)) puts("Yes");
		else puts("No");
	}
	return 0;
}