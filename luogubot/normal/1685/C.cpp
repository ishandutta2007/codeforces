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
int n,a[N];char s[N];
int val(char x){return x=='('?1:-1;}
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",s+1);
		int l=-1,r=-1,mx=-1,pos=1;For(i,1,2*n){
			a[i]=a[i-1]+val(s[i]);
			if(a[i]<0){if(l==-1)l=i;r=i;}
			if(a[i]>mx)mx=a[i],pos=i;
		}if(l==-1)puts("0");
		else{
			int L=0,R=2*n;For(i,0,l)if(a[i]>a[L])L=i;Rof(i,2*n,r+1)if(a[i]>a[R])R=i;
			reverse(s+L+1,s+R+1);int x=0,fl=1;For(i,1,2*n){
				x+=val(s[i]);if(x<0)fl=0;
			}if(fl)printf("1\n%d %d\n",L+1,R);else printf("2\n%d %d\n%d %d\n",1,pos,pos+1,2*n);
		}
	}
	return 0;
}