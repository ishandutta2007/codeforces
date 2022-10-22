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
const int N=2e5+10,p=998244353;
int n;char a[N][3];
int fac[N],ifac[N];
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
void init(int n=N-10){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
}
inline int C(int n,int m){
	return 0<=m&&m<=n?fac[n]*ifac[m]%p*ifac[n-m]%p:0;
}
signed main(){
	init();int _0=0,_1=0,fl=0;
	For(i,1,n=read()){
		scanf("%s",a[i]);
		_0+=(a[i][0]=='W')+(a[i][1]=='W');
		_1+=(a[i][0]=='B')+(a[i][1]=='B');
		fl|=(a[i][0]==a[i][1]&&a[i][0]!='?');
	}if(max(_0,_1)>n)puts("0");else{
		int ans=C(2*n-_0-_1,n-_0);
		if(!fl){
			int del=1;For(i,1,n)(del*=(1+(a[i][0]==a[i][1])))%=p;
			(ans+=p-del)%=p;
			fl=1;For(i,1,n)fl&=(a[i][0]!='W'&&a[i][1]!='B');(ans+=fl)%=p;
			fl=1;For(i,1,n)fl&=(a[i][0]!='B'&&a[i][1]!='W');(ans+=fl)%=p;
		}cout<<ans<<endl;
	}
	return 0;
}//dsadas