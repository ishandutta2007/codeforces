#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=1e3+10,M=(1<<17)+10,p=998244353;
int n,f[18][M],pw[18][N];char a[N],b[18];
void solve(int *f){
	For(t,0,16)For(i,0,(1<<17)-1)if(!(i&(1<<t)))(f[i|(1<<t)]+=f[i])%=p;
}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),scanf("%s",a+1);int k=0;For(i,1,n)k+=(a[i]=='?');
	For(i,1,17){pw[i][0]=1;For(j,1,n)pw[i][j]=pw[i][j-1]*i%p;}
	For(i,1,n){
		for(int c=0,S=0,d=0,l=i,r=i;l>=1&&r<=n&&(a[l]=='?'||a[r]=='?'||a[l]==a[r]);l--,r++){
			if(a[l]=='?'&&a[r]=='?')c+=(l!=r);
			else if(a[l]==a[r]);
			else if(a[l]!='?')S|=(1<<a[l]-'a'),d++;
			else S|=(1<<a[r]-'a'),d++;
			For(t,1,17)(f[t][S]+=pw[t][k-d-c])%=p;
		}for(int c=0,S=0,d=0,l=i,r=i+1;l>=1&&r<=n&&(a[l]=='?'||a[r]=='?'||a[l]==a[r]);l--,r++){
			if(a[l]=='?'&&a[r]=='?')c++;
			else if(a[l]==a[r]);
			else if(a[l]!='?')S|=(1<<a[l]-'a'),d++;
			else S|=(1<<a[r]-'a'),d++;
			For(t,1,17)(f[t][S]+=pw[t][k-d-c])%=p;
		}
	}For(t,1,17)solve(f[t]);int q=read();while(q--){
		scanf("%s",b+1);int T=0;For(i,1,strlen(b+1))T|=(1<<b[i]-'a');
		printf("%lld\n",f[strlen(b+1)][T]);
	}return 0;
}