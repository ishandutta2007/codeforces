#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int ans,m,n,t_case;
char s[maxn];
void dfs(int k,int tot1,int tot2){
	if(k>=ans)return;
	if(k&1){
		if(s[k]=='0'){
			if(tot1+(10-k)/2<tot2){
				ans=k;
				return;
			}
			dfs(k+1,tot1,tot2);
		}
		else if(s[k]=='1'){
			if(tot2+(10-k+1)/2<tot1+1){
				ans=k;
				return;
			}
			dfs(k+1,tot1+1,tot2);
		}
		else{
			if(tot1+(10-k)/2<tot2||tot2+(10-k+1)/2<tot1+1){
				ans=k;
				return;
			}
			dfs(k+1,tot1,tot2);
			dfs(k+1,tot1+1,tot2);
		}
	}
	else{
		if(s[k]=='0'){
			if(tot2+(10-k)/2<tot1){
				ans=k;
				return;
			}
			dfs(k+1,tot1,tot2);
		}
		else if(s[k]=='1'){
			if(tot1+(10-k)/2<tot2+1){
				ans=k;
				return;
			}
			dfs(k+1,tot1,tot2+1);
		}
		else{
			if(tot2+(10-k)/2<tot1||tot1+(10-k)/2<tot2+1){
				ans=k;
				return;
			}
			dfs(k+1,tot1,tot2);
			dfs(k+1,tot1,tot2+1);
		}
	}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		ans=10;
		dfs(1,0,0);
		printf("%d\n",ans);
	}
}