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
const int N=1e5+10;
int n,a[N],b[N];
signed main(){
	int T=read();while(T--){
		unordered_map<int,int> mp0,mp1;
		n=read();For(i,1,n)a[i]=read();For(j,1,n)b[j]=read();
		int now=0; 
		Rof(j,29,0){
			mp0.clear(),mp1.clear();
			int L=((1<<30)-(1<<j));
			For(i,1,n){
				int x=b[i]&L^L;
				if(b[i]>>j&1)mp0[x]++;
				else mp1[x]++;
			}int fl=1;
			For(i,1,n){
				int x=a[i]&L;
				if(a[i]>>j&1)fl&=(mp1[x]-->=1);
				else fl&=(mp0[x]-->=1);
			}if(fl)now+=(1<<j);
			else For(i,1,n){
				if(b[i]>>j&1)b[i]-=(1<<j);
				if(!(a[i]>>j&1))a[i]+=(1<<j);
			}
		}cout<<now<<endl;
	}
	return 0;
}