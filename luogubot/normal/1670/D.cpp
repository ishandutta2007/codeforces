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
const int N=1e5+10;
int f[N],m=1e5;
signed main(){
	For(i,1,m){
		int x,y,z;x=y=z=i/3;
		if(i%3==0);
		else if(i%3==1)x++;
		else x++,y++;
		assert(max({x,y,z})-min({x,y,z})<=1);
		f[i]=2*(x*y+x*z+y*z);
	}
	int T=read();while(T--)cout<<lower_bound(f+1,f+1+m,read())-f<<endl;
	return 0;
}