#include<cstdio>
const int MAXN=5005;
int n;
char s[MAXN],t[MAXN],ans[MAXN];
int res;
bool Check(){
	for(int i=1; i<=n; i++)
		if(ans[i]!=t[i]) return t[i]<ans[i];
	return 0;
}
int main(){
	//freopen("B.in","r",stdin);
	int tt; scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int k=1; k<=n; k++){
			int cnt=0;
			for(int i=k; i<=n; i++)
				t[++cnt]=s[i];
			if(n-k&1){
				for(int i=1; i<k; i++)
					t[++cnt]=s[i];
			}else{
				for(int i=1; i<k; i++)
					t[++cnt]=s[k-i];
			}
			if(k==1||Check()){
				for(int i=1; i<=n; i++)
					ans[i]=t[i];
				res=k;
			}
		}
		ans[n+1]=0;
		puts(ans+1);
		printf("%d\n",res);
	}
	return 0;
}