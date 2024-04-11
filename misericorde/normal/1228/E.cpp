
#include <bits/stdc++.h>
#define maxn 255
//lgoj
#define ll long long
const int ouuan=1e9+7;
 
int n,C[maxn][maxn],ans=1;
int a[maxn],b[maxn];
 
int qpow(int a,int b){
	if (b==0)return 1;
	int d=qpow(a,b>>1);d=(ll)d*d%ouuan;
	if (b&1)d=(ll)d*a%ouuan;
	return d;
}
int main(){
    int k;scanf("%d%d",&n,&k);
    for (int i=0;i<=250;++i){
    	C[i][0]=1;
        for (int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%ouuan;
    }
    for(int i=1;i<=n;++i)a[i]=b[i]=k-1;
    a[n+1]=b[n+1]=-1;
    for (int x=0,y=0;x<n||y<n;){
        int lim=std::max(a[x+1],b[y+1]),x1=x,y1=y,tmp=0;
        while (a[x+1]==lim)x++;while (b[y+1]==lim)y++;
        for (int i=0;i<=x-x1;++i)
            for (int j=0;j<=y-y1;++j){
                int S1=(x-i)*(y-j)-x1*y1,S2=x*y-S1-x1*y1;
                int res=(ll)qpow(lim+1,S1)%ouuan*qpow(lim,S2)%ouuan*C[x-x1][i]%ouuan*C[y-y1][j]%ouuan;
                if ((i+j)&1) tmp=((ll)tmp-res+ouuan)%ouuan;
                else tmp=(tmp+res)%ouuan;
            }
        ans=(ll)ans*tmp%ouuan;
    }printf("%d",ans);
	return 0;
}