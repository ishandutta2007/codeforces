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
const int N=2e5+10;
int n,p[N];
vector<int> a,b;int cnt,lim;
int ask(int i,int j){
	assert(++cnt<=lim);
	printf("? %d %d\n",i,j),endout;
	return read();
}
signed main(){
	int T=read();while(T--){
		a.clear();
		n=read();For(i,1,(1<<n))a.push_back(i);
		cnt=0;lim=((1<<n+1)+2)/3;
		while(a.size()>2){
			b.clear();
			for(int i=0;i<a.size();i+=4){
				int A=a[i],B=a[i+1],C=a[i+2],D=a[i+3];
				int u=ask(A,C);
				if(u==0){
					u=ask(B,D);
					if(u==1)b.push_back(B);
					else assert(u==2),b.push_back(D);
				}else if(u==1){
					u=ask(A,D);
					if(u==1)b.push_back(A);
					else assert(u==2),b.push_back(D);
				}else{
					u=ask(B,C);
					if(u==1)b.push_back(B);
					else assert(u==2),b.push_back(C);
				}
			}a=b;
		}
		if(a.size()==2){int u=ask(a[0],a[1]);if(u==2)swap(a[0],a[1]);}
		printf("! %d\n",a[0]),endout;
	}
	return 0;
}