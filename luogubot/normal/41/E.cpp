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
signed main(){
	int n=read();
	if(n==1)puts("0");
	else if(n==2)puts("1\n1 2");
	else if(n==3)puts("2\n1 2\n2 3\n");
	else{
		cout<<(n>>1)*(n+1>>1)<<endl;
		For(i,1,n>>1)For(j,(n>>1)+1,n)printf("%d %d\n",i,j);
	}
	return 0;
}//dasdas