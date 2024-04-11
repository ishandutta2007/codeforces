#include<cstdio>
#include<cstring>
const int N=2e5+5;
char s[N];
int n,ans1,ans2,T,ss;
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans1=ans2=ss=0;
		for(int i=1;i<=n;i++)
			ss+=s[i]-'a'+1;
		if(n%2==0) ans1=ss;
		else{
			ans1=ss-Min(s[1]-'a'+1,s[n]-'a'+1);
			ans2=ss-ans1;
		}
		if(ans1>ans2) printf("Alice %d\n",ans1-ans2);
		else printf("Bob %d\n",ans2-ans1);
	}
	return 0;
}