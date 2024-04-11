#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int m,n,pre[maxn],nxt[maxn],t_case;
char s[maxn];
inline void del(int k){
	nxt[pre[k]]=nxt[k];
	pre[nxt[k]]=pre[k];
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		memset(s,0,sizeof s);
		scanf("%s",s+1);
		n=strlen(s+1);
		for(ri i=1;i<=n;++i)pre[i]=i-1,nxt[i]=i+1;
		bool flag=false;
		for(ri i=2,lst=-1;i<=n;++i)
			if(s[i]<s[pre[i]]){
				if(i-lst<2){flag=true;break;}
				if(s[pre[pre[i]]]=='1'||pre[i]-lst<2)lst=i,del(i);
				else lst=pre[i],del(pre[i]);
			}
		puts(flag?"NO":"YES");
	}
	return 0;
}