#include<cstdio>
const int N=200002,M=26;
const int G1=998244353,G2=1000000007;
const int H1=131,H2=233;
int n,q,i,j,lst[M],pre[N],Hs1[N],Hs2[N],Nxt[N][M],l1,l2,r1,r2,len;
int P1[N],P2[N];
char s[N];
void init(){
	scanf("%d%d%s",&n,&q,s+1);
	P1[0]=P2[0]=1;
	for(i=1;i<=n;i++){
		pre[i]=i-lst[s[i]-97];
		lst[s[i]-97]=i;
		P1[i]=1ll*P1[i-1]*H1%G1;
		P2[i]=1ll*P2[i-1]*H2%G2;
		Hs1[i]=(1ll*Hs1[i-1]*H1+pre[i])%G1;
		Hs2[i]=(1ll*Hs2[i-1]*H2+pre[i])%G2;
	}
	for(j=0;j<M;j++)
		Nxt[n+1][j]=n+1;
	for(i=n;i;i--){
		for(j=0;j<M;j++)
			Nxt[i][j]=Nxt[i+1][j];
		Nxt[i][s[i]-97]=i;
	}
}
int Hash1(int l,int r){
	int Hash=((Hs1[r]-1ll*Hs1[l-1]*P1[r-l+1])%G1+G1)%G1;
	for(int i=0;i<M;i++)
		if(Nxt[l][i]<=r)
			Hash=((Hash-1ll*pre[Nxt[l][i]]*P1[r-Nxt[l][i]])%G1+G1)%G1;
	return Hash;
}
int Hash2(int l,int r){
	int Hash=((Hs2[r]-1ll*Hs2[l-1]*P2[r-l+1])%G2+G2)%G2;
	for(int i=0;i<M;i++)
		if(Nxt[l][i]<=r)
			Hash=((Hash-1ll*pre[Nxt[l][i]]*P2[r-Nxt[l][i]])%G2+G2)%G2;
	return Hash;
}	
void work(){
	while(q--){
		scanf("%d%d%d",&l1,&l2,&len);
		r1=l1+len-1;
		r2=l2+len-1;
		//printf("%d %d %d %d\n",Hash1(l1,r1),Hash1(l2,r2),Hash2(l1,r1),Hash2(l2,r2));
		if(Hash1(l1,r1)==Hash1(l2,r2)&&Hash2(l1,r1)==Hash2(l2,r2))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
int main(){
	init();
	work();
}