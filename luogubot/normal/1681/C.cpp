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
const int N=100+10; 
int n,a[N],b[N],A[N],B[N];
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> g;
signed main(){
	int T=read();while(T--){
		For(i,1,n=read())A[i]=a[i]=read();For(i,1,n)B[i]=b[i]=read();
		g.clear();
		sort(A+1,A+1+n),sort(B+1,B+1+n);
		For(i,1,n){
			if(A[i]!=a[i]){
				For(j,i+1,n)if(a[j]==A[i])
					swap(a[i],a[j]),swap(b[i],b[j]),g.push_back(pi(i,j));
			}
		}For(i,1,n){
			if(B[i]!=b[i]){
				For(j,i+1,n)if(b[j]==B[i])
					swap(a[i],a[j]),swap(b[i],b[j]),g.push_back(pi(i,j));
			}
		}int fl=1;For(i,1,n-1)if(a[i]>a[i+1])fl=0;if(!fl)puts("-1");
		else{cout<<g.size()<<endl;for(auto v:g)printf("%d %d\n",v.fi,v.se);}
	}
	return 0;
}