#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n,k;char a[N];
signed main(){
	int T=read();while(T--){
		n=read(),k=read(),scanf("%s",a+1);
		int ans=0;
		For(i,1,n)if(a[i]=='1')ans+=11;
		if(!ans){puts("0");continue;}int L=-1,R=-1;
		For(i,1,n)if(a[i]=='1'){L=i-1;break;}
		Rof(i,n,1)if(a[i]=='1'){R=n-i;break;}
		if(ans==11){
			if(k>=R)ans-=10;
			else if(k>=L)ans--;
		}else{
			if(k>=R)ans-=10,k-=R;
			if(k>=L)ans--;
		}cout<<ans<<endl;
	}
	return 0;
}