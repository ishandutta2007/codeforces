#include<cstdio>
const int N=100002,M=200;
char s[N];
int n,cnt,p[M],i,l,r,g,ans=N;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++){
		if(p[s[i]]==0)
			cnt++;
		p[s[i]]=1;
	}
	for(i=0;i<M;i++)
		p[i]=0;
	for(l=r=1;r<=n;r++){
		if(p[s[r]]==0)
			g++;
		p[s[r]]++;
		while(g==cnt&&p[s[l]]>1)
			p[s[l]]--,l++;
		if(g==cnt)
			ans=min(ans,r-l+1);
	}
	printf("%d",ans);
}