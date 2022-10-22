#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int a[4],f[4],n,nxt[4]={1,2,3,0},t,pre[4]={3,0,1,2};
inline int cmp(int x,int y){
	return a[x]==a[y]?(f[x]<f[y]?x:y):(a[x]>a[y]?x:y);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&a[0],&a[1],&a[2],&a[3]);
		memset(f,0,sizeof f);
		for(ri i=0;i<4;++i)
			if(a[i]==n)
				++f[nxt[i]],++f[pre[i]];
			else if(a[i]==n-1)
				++f[cmp(nxt[i],pre[i])];
		bool flag=false;
		for(ri i=0;i<4;++i)
			if(f[i]>a[i])
				flag=true;
		puts(flag?"NO":"YES");
	}
	return 0;
}