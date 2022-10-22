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
#define ull unsigned long long
const int N=5e5+10;
int n,a[N],c[N],pre[N],lst[N],ans,nxt[N];
ull val[N],h[N];
mt19937 rnd(1919810);
unordered_map<ull,int> mp;
signed main(){
    For(i,1,n=read())a[i]=read(),val[i]=(1ull*rnd()<<32)|rnd();
	For(i,1,n)pre[i]=lst[a[i]],lst[a[i]]=i;mp[0]=1;
	For(i,1,n)lst[i]=n+1;Rof(i,n,1)nxt[i]=lst[a[i]],lst[a[i]]=i;
    For(i,1,n){
    	h[i]=h[i-1],h[i]-=val[a[i]]*c[a[i]];
    	(++c[a[i]])%=3,h[i]+=val[a[i]]*c[a[i]];
	}int pos=-1;
	For(i,1,n){
		int j=pre[pre[pre[i]]]-1;//
		while(pos<j)mp[h[++pos]]--;
		ans+=mp[h[i]],mp[h[i]]++; 
	}cout<<ans<<endl;
	return 0;
}//fassdas