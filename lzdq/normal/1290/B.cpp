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