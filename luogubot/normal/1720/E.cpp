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
int n,k,a[N][N],num[N*N],t[N*N],tot,x,now;
void add1(int i,int l,int r){For(j,l,r)if(++t[a[i][j]]==num[a[i][j]])now++;}
void add2(int j,int l,int r){For(i,l,r)if(++t[a[i][j]]==num[a[i][j]])now++;}
void del1(int i,int l,int r){For(j,l,r)if(t[a[i][j]]--==num[a[i][j]])now--;}
void del2(int j,int l,int r){For(i,l,r)if(t[a[i][j]]--==num[a[i][j]])now--;}
signed main(){
	n=read(),k=read();
	For(i,1,n)For(j,1,n){
		a[i][j]=read();
		if(!num[a[i][j]])tot++;
		num[a[i][j]]++;
	}if(tot<=k)return printf("%d\n",k-tot),0;x=tot-k,now=0;
	int fl=0;For(i,1,n){
		memset(t,0,sizeof t),now=0;
		for(int l=1,r=0;l<=n;){
			while(now<x&&r<n&&i+r-l+1<=n)r++,add1(i+r-l,l,r),add2(r,i,i+r-l-1);
			fl|=(now==x||now==x+1),del1(i+r-l,l,r),del2(l,i,i+r-l-1),l++;
		}if(fl)break;
	}puts(fl?"1":"2");
	return 0;
}