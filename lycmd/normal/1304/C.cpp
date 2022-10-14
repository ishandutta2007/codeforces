#include<bits/stdc++.h>
int const N=233;
int T,n,m,t[N],l[N],r[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&t[i],&l[i],&r[i]);
		int nowl=m,nowr=m,flg=1;
		for(int i=1;i<=n&&flg;i++){
			nowl-=t[i]-t[i-1];
			nowr+=t[i]-t[i-1];
			if(nowl>r[i]||nowr<l[i])flg=0;
			else nowl=std::max(l[i],nowl),nowr=std::min(r[i],nowr);
		}
		puts(flg?"YES":"NO");
	}
}