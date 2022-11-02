#include<cstdio>
int n,i,ans=1000002;
char s[100002];
int abs(int x){
	return x>0?x:-x;

}
int min(int x,int y){
	return x<y?x:y;
}
int p(int x){
	x=abs(x);
	return min(x,26-x);
}

int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i+3<=n;i++)
	ans=min(ans,p(s[i]-'A')+p(s[i+1]-'C')+p(s[i+2]-'T')+p(s[i+3]-'G'));
	printf("%d",ans);
//	while(1);
}