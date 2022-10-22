#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int op=0;
int p[1000010],cnt,ri,rj,rk;
inline int C(int n){return n*(n-1)/2;}
inline int ask(int l,int r){
	if(l>r)return 0;
	printf("? %lld %lld\n",l,r),endout;
	assert(++cnt<=40);
	if(op){
		int c=0;
		int L=max(l,ri),R=min(r,rj-1);if(L<=R)c+=C(R-L+1);
		L=max(l,rj),R=min(r,rk);if(L<=R)c+=C(R-L+1);
		return c;
	}
	return read();
}
inline int calc(int n){
	int l=1,r=1e9;while(l<=r){
		int m=l+r>>1;
		if(C(m)>=n)r=m-1;
		else l=m+1;
	}return r+1;
}
mt19937 R(time(NULL));inline int rd(int l,int r){return R()%(r-l+1)+l;}
signed main(){
	int T=read();while(T--){
		int n=read();cnt=0;
		if(op){
//			ri=read(),rj=read(),rk=read();
//			rk=n,rj=rk-1,ri=rj-2;
//			ri=rd(1,n-10),rj=rd(ri+2,n-1),rk=rd(rj+1,n);
//			printf("ans = %lld %lld %lld\n",ri,rj,rk);
		}
		int all=ask(1,n);
		int l=1,r=n;while(l<=r){
			int mid=l+r>>1;
//			printf("[%lld,%lld] [%lld,%lld]\n",l,mid,mid+1,r); 
			int L=ask(l,mid),R=all-L;
			if(L==all)r=mid;
			else if(L==0)l=mid;
			else{
				int h=L-ask(l,mid-1)+1;
				if(C(h)==L){
//					printf("now mid = %lld\n",mid);
					int tl=h;
					h=ask(mid+1,r)-ask(mid+2,r)+1;
					if(C(tl)+C(h)==all){
						int J=mid+1,I=J-tl,K=J+h-1;
						printf("! %lld %lld %lld\n",I,J,K),endout;
					}else{
						int ll=tl+h;
						int rl=calc(all-C(ll));
						int J=mid+h+1,I=J-ll,K=J+rl-1;
						printf("! %lld %lld %lld\n",I,J,K),endout;
					}
				}else{
					int rl=h+calc(ask(mid+1,r));
					int ll=calc(all-C(rl));
					int J=mid-h+1,I=J-ll,K=J+rl-1;
					printf("! %lld %lld %lld\n",I,J,K),endout;
				}
				break;
			}
		}
	}
	return 0;
}