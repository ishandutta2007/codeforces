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
const int N=2e5+10;
int n,a[N],l,r;
signed main(){
	int TTT=read();while(TTT--){
		n=read(),l=read(),r=read();int cl=0,cr=0,ans=0,mxl=0,mxr=0;
		For(i,1,n)a[i]=0;
		For(i,1,l)a[read()]++;
		For(i,1,r)a[read()]--;
		For(i,1,n)if(a[i]){
			if(a[i]<0){
				cl-=a[i];
				mxl+=abs(a[i])/2;
			}else{
				cr+=a[i];
				mxr+=abs(a[i])/2;
			}
		}ans+=min(cl,cr);
		if(cl<cr){
			ans+=min(cr-cl>>1,mxr)+max(0ll,(cr-cl)/2-mxr)*2;
		}if(cr<cl){
			ans+=min(cl-cr>>1,mxl)+max(0ll,(cl-cr)/2-mxl)*2;
		}
		cout<<ans<<endl;
	}
	return 0;
}