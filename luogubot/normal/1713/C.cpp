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
const int N=5e5+10;
int n,a[N],ok[N],vis[N];
signed main(){
	for(int i=0;i*i<N;i++)ok[i*i]=1;
	int Tc=read();while(Tc--){
		n=read();int fl=1;For(i,0,n-1)vis[i]=0;
		for(int i=n-1,j;i>=0;i=j-1){
			j=i;while(!ok[j+i]&&j>0)j--;
			if(!ok[j+i]){fl=0;break;}
			For(k,j,i)a[k]=i-k+j;
		}if(!fl)puts("-1");else For(i,0,n-1){
			printf("%d%c",a[i]," \n"[i==iEND]);
			assert(a[i]>=0&&a[i]<n);
			assert(ok[a[i]+i]),assert(!vis[a[i]]); 
			vis[a[i]]=1;
		} 
	}
	return 0;
}