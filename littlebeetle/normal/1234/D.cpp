#include<cstdio>
const int N=100002;
int n,q,l,r,pos,i,opt,ans;
char s[N],t[3];
struct p{
	int f[N];
	void Update(int x,int y){
		while(x<=n)
			f[x]+=y,x+=x&-x;
	}
	int Query(int x){
		int sum=0;
		while(x)
			sum+=f[x],x-=x&-x;
		return sum;
	}
}g[26];
int main(){
	scanf("%s%d",s+1,&q);
	while(s[n+1])n++;
	for(i=1;i<=n;i++)
		g[s[i]-97].Update(i,1);
	while(q--){
		scanf("%d",&opt);
		if(opt==2){
			scanf("%d%d",&l,&r);
			ans=0;
			for(i=0;i<26;i++)
				ans+=(g[i].Query(r)-g[i].Query(l-1))>0;
			printf("%d\n",ans);
		}
		else{
			scanf("%d%s",&pos,t);
			g[s[pos]-97].Update(pos,-1);
			s[pos]=t[0];
			g[s[pos]-97].Update(pos,1);
		}
	}
	//while(1);
}