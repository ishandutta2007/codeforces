#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1010;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int m,n,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s%s",s+1,t+1);
		ri n=strlen(s+1),m=strlen(t+1);
		bool flag=false;
		for(ri i=1;i<=n;++i){
			ri j=i,k=1;
			for(;j<=n&&k<=m&&s[j]==t[k];++j,++k){
				ri _j=j-1,_k=k+1;
				for(;_j>0&&_k<=m&&s[_j]==t[_k];--_j,++_k);
				if(_k>m){
					flag=true;
					break;
				}
			}
		}
		puts(flag?"YES":"NO");
		memset(s,0,sizeof s),memset(t,0,sizeof t);
	}
}