#include<cstdio>
const int N=200002;
int n,l[N],r[N],m,i,j,ans;//
char s[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%s",&n,s+1);//
	for(i=1;i<=n;i++)
		if(s[i]=='G'){
			j=i;
			while(s[j]=='G')
				j++;
			ans=max(ans,j-i);
			l[++m]=i;
			r[m]=j;
			i=j;
		}
	if(m>1)
		ans++;
	for(i=1;i<m;i++)
		if(r[i]+1==l[i+1])
			ans=max(ans,r[i+1]-l[i]-(m==2));
	printf("%d",ans);
	return 0;
}