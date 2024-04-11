#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
#define endout fflush(stdout) 
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e3+10;
int n,m;
struct node{
	int val,id;
	bool operator < (const node &x) const {
		return val<x.val;
	}
}a[N];
string s;
int ask(){
	cout<<"? "<<s<<endl,endout;
	return read();
}
signed main(){
	n=read(),m=read();
	For(i,1,m)s+="0";
	For(i,0,m-1){
		s[i]='1';a[i]=(node){ask(),i},s[i]='0';
	}sort(a,a+m);int now=a[0].val;s[a[0].id]='1';
	For(i,1,m-1){
		int id=a[i].id; 
		s[id]='1';
		int tmp=ask();
		if(tmp-now==a[i].val)now=tmp;
		else s[id]='0';
	}cout<<"! "<<ask()<<endl,endout;
	return 0;
}