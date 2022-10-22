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
int n;char a[N],s1[N],s2[N];
bool check(char* s){
	int d=0;For(i,1,n){
		if(s[i]=='(')d++;
		else d--;
		if(d<0)return 0;
	}if(d)return 0;
	return 1;
}
signed main(){
	int T=read();while(T--){
		n=read(),scanf("%s",a+1);
		int c=0,d=0;For(i,1,n)c+=a[i]=='0';
		if(c&1){puts("NO");continue;}
//		puts("YES");
		int L=n-c>>1;
		For(i,1,n)if(a[i]=='0'){
			d++;
			if(d&1)s1[i]='(',s2[i]=')';
			else s1[i]=')',s2[i]='(';
		}else{
			if(L)L--,s1[i]=s2[i]='(';
			else s1[i]=s2[i]=')';
		}if(!check(s1)||!check(s2))puts("NO");
		else{puts("YES");For(i,1,n)putchar(s1[i]);puts("");For(i,1,n)putchar(s2[i]);puts("");}
	}
	return 0;
}