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
//const int N=1e6+10;
//int n,k,a[N],b[N],s;
//void work(){
//	For(i,1,n)if(i!=s)b[(i+n-2)%n+1]+=(a[i]>>1),b[i%n+1]+=(a[i]+1>>1);else b[i%n+1]+=a[i];
//	For(i,1,n)a[i]=b[i],b[i]=0;
//}
#define endout fflush(stdout)
int get(int x){
	printf("? %d\n",x);puts(""),endout;
	return read();
}
void ans(int x){
	printf("! %d\n",x);puts(""),endout;
	exit(0);
}
signed main(){
//	n=read(),k=read(),s=2;For(i,1,n)a[i]=k;
//	For(T,1,30){
//		For(i,1,n)printf("%d ",a[i]);puts("");
//		work();
//	}
	int n=read(),k=read(),s=1,c=2;
	while(1){
		s=(s-1)%n+1;
		int val=get(s);
		if(val==k)s+=c++;
		else if(val<k){// 
			while(1){
				s=s%n+1;
				val=get(s);
				if(val==k)ans(s); 
			}
		}else{// 
			while(1){
				s=(s+n-2)%n+1;
				val=get(s);
				if(val==k)ans(s);
			}
		}
	}
	return 0;
}