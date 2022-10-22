#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e4+10;
char s[N];
int q[N],l=1,r=0;
char ch[5];
char in[N];
char qry1(int i){
	printf("? 1 %d\n",i),endout;
	scanf("%s",ch);return ch[0];
}
int qry2(int l,int r){
	printf("? 2 %d %d\n",l,r),endout;
	return read();
}
//char qry1(int i){
//	return in[i];
//}
//int tag,vis[30];
//int qry2(int l,int r){
//	tag++;int c=0;For(i,l,r)if(vis[in[i]-'a']!=tag)c++,vis[in[i]-'a']=tag;
//	return c;
//}
char get(int l,int r,int i){
	int R=r;
//	Rof(j,r,l)if(qry2(q[j],i)!=R-j+2)return s[q[j]];
//	puts("-1");return qry1(i);
	int ret=-1;
	while(l<=r){
		int m=l+r>>1;
		if(qry2(q[m],i)!=R-m+2)l=m+1,ret=m;
		else r=m-1;
	}
	if(ret!=-1)return s[q[ret]];
	else return qry1(i);
}
int lst[30]; 
signed main(){
	int n=read();
//	scanf("%s",in+1);
	s[1]=qry1(1);lst[s[1]-'a']=1;
	For(i,2,n){
		l=1,r=0;
		For(i,0,25)if(lst[i])q[++r]=lst[i];
		sort(q+1,q+r+1);
		if(r-l+1<26){
			int val=qry2(1,i);
			if(val>r-l+1)s[i]=qry1(i);
			else s[i]=get(l,r,i);
		}else{
			s[i]=get(l,r,i);
		}lst[s[i]-'a']=i;
	}printf("! ");For(i,1,n)putchar(s[i]);puts(""),endout;
	return 0;
}