#include <bits/stdc++.h>
#define ll long long
ll f[100][3][3];
int t,l,r,l1[100],l2[100];

void fill(ll x,int *a){
	for(int i=0;i<33;++i){
		a[33-i]=(x>>i)&1;
	}
}

ll calc(int a,int b){
	if (a<0)return 0;
	if (b<0)return 0; 
	fill(a,l1);fill(b,l2);
//	for(int i=1;i<=31;++i)printf("%d ",l1[i]);printf("\n");
//	for(int i=1;i<=31;++i)printf("%d ",l2[i]);printf("\n");
	std::memset(f,0,sizeof(f));
	f[0][1][1]=1;
	for(int i=1;i<=33;++i){
	for(int s1=0;s1<=1;++s1)
		for(int s2=0;s2<=1;++s2){
			if (s1==1&&s2==1)continue;
			f[i][0][0]+=f[i-1][0][0];
			if (s2<l2[i])f[i][0][0]+=f[i-1][0][1];
			if (s1<l1[i])f[i][0][0]+=f[i-1][1][0];
			if (s1<l1[i]&&s2<l2[i])f[i][0][0]+=f[i-1][1][1];
			if (s2==l2[i])f[i][0][1]+=f[i-1][0][1];
			if (s1<l1[i]&&s2==l2[i])f[i][0][1]+=f[i-1][1][1];
			if (s1==l1[i])f[i][1][0]+=f[i-1][1][0];
			if (s1==l1[i]&&s2<l2[i])f[i][1][0]+=f[i-1][1][1];
			if (s1==l1[i]&&s2==l2[i])f[i][1][1]+=f[i-1][1][1];
		}//printf("%d %d %d %d\n",f[i][0][0],f[i][0][1],f[i][1][0],f[i][1][1]);
	}
				
	return f[33][0][0]+f[33][1][1]+f[33][0][1]+f[33][1][0];
}
			

void solve(){
	scanf("%d%d",&l,&r);
	std::cout<<calc(r,r)+calc(l-1,l-1)-calc(r,l-1)-calc(l-1,r)<<std::endl;
}

int main(){
	scanf("%d",&t);
	while (t--)solve();
	return 0;
}