#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=20;
const int M=100100;
void FWT(LL *x,int n){
    if(n==1)return;
    int l=n>>1;
    FWT(x,l);
    FWT(x+l,l);
    for(int i=0;i<l;i++){
        LL &u=x[i],&v=x[l+i];
        LL uu=u,vv=v;
        u=uu+vv;
        v=uu-vv;
    }
}
void IFWT(LL *x,int n){
    if(n==1)return;
    int l=n>>1;
    for(int i=0;i<l;i++){
        LL &u=x[i],&v=x[l+i];
        LL uu=u,vv=v;
        u=(uu+vv)>>1;
        v=(uu-vv)>>1;
    }
    IFWT(x,l);
    IFWT(x+l,l);
}
int n,m;
char s[N][M]={'\0'};
LL a[1<<N]={0},b[1<<N]={0};
int pc(int x){
	return x?pc(x&(x-1))+1:0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char &ch=s[i][j];
			do{
				ch=getchar();
			}while(!isdigit(ch));
		}
	}
	for(int i=0;i<m;i++){
		int c=0;
		for(int j=0;j<n;j++){
			c=(c<<1)|(s[j][i]^'0');
		}
		a[c]++;
	}
	int x=1<<n;
	for(int j=0;j<x;j++){
		b[j]=min(pc(j),pc((x-1)^j));
	}
	FWT(a,x);
	FWT(b,x);
	for(int i=0;i<x;i++){
		a[i]*=b[i];
	}
	IFWT(a,x);
	int ans=INT_MAX;
	for(int i=0;i<x;i++){
		ans=min(ans,(int)a[i]);
	}
	printf("%d\n",ans);
	return 0;
}