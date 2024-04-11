#include<cstdio>
#include<cstring>
const int MAXN=1e5+5;
int n,q;
char s[MAXN];
int rsum[30][MAXN];
int ans;
inline void add(int *a,int x,int y){
	for(int i=x;i<=n;i+=i&-i)
		a[i]+=y;
}
inline int query(int *a,int x){
	int res=0;
	for(int i=x;i;i-=i&-i)
		res+=a[i];
	return res;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		add(rsum[s[i]-'a'],i,1);
	scanf("%d",&q);
	while(q--){
		int opt,x,y;
		scanf("%d",&opt);
		if(opt==1){
			char ch[2];
			scanf("%d%s",&x,ch);
			add(rsum[s[x]-'a'],x,-1);
			add(rsum[ch[0]-'a'],x,1);
			s[x]=ch[0];
		}else{
			scanf("%d%d",&x,&y);
			ans=0;
			for(int i=0;i<26;i++)
				if(query(rsum[i],y)>query(rsum[i],x-1)) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}