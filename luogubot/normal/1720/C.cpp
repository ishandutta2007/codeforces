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
const int N=510;
int n,m;char a[N][N]; 
signed main(){
	int T=read();while(T--){
		n=read(),m=read();
		For(i,1,n)scanf("%s",a[i]+1);
		int fl1=0,fl2=0,all=0;
		For(i,1,n)For(j,1,m)fl1|=a[i][j]=='0',all+=a[i][j]=='1';
		For(i,1,n)For(j,1,m)fl2|=(a[i][j]=='0'&&
			(
				j<m&&a[i][j+1]=='0'||
				i<n&&a[i+1][j]=='0'||
				i<n&&j<m&&a[i+1][j+1]=='0'||
				i>1&&j<m&&a[i-1][j+1]=='0'
			));
		printf("%d\n",all-(fl1^1)-(fl2^1));
	}
	return 0;
}