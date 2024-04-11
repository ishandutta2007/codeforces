#include<bits/stdc++.h>
typedef long long i64;
int n,m,vs[4][100007],vp[4];
i64 s1[100007],s2[100007],ans=0,now=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		vs[x][++vp[x]]=y;
	}
	for(int i=1;i<=3;++i)std::sort(vs[i]+1,vs[i]+vp[i]+1,std::greater<int>());
	for(int i=1;i<=vp[1];++i)s1[i]=s1[i-1]+vs[1][i];
	for(int i=1;i<=vp[2];++i)s2[i]=s2[i-1]+vs[2][i];
	for(int i=0;i<=vp[3]&&m>=0;++i){
		int L=0,R=std::min(vp[2],m/2),M;
		while(L<R){
			M=L+R>>1;
			int m2=std::min(m-M*2,vp[1]);
			if(M*2+m2<m-1||vs[2][M]>vs[1][m2]*2)L=M+1;
			else R=M;
		}
		for(int x=std::max(0,M-2);x<=std::min(vp[2],M+2);++x){
			if(x*2>m)continue;
			int y=std::min(vp[1],m-x*2);
			i64 a1=now+s1[y]+s2[x];
			if(a1>ans)ans=a1;
		}
		m-=3;now+=vs[3][i+1];
	}
	printf("%I64d\n",ans);
	return 0;
}