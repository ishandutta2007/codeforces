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
const int N=1e5+10;
int n,a[N],x;
bool check(int t){
	int now=0;
	For(i,1,n){
		if(now+a[i]!=x){
			now+=a[i];
		}else{
			if(t){
				swap(a[i],a[n]);
				return check(0);
			}else return 0;
		}
	}return 1;
}
signed main(){
	int TTT=read();while(TTT--){
		int n=read(),fl=0;
		if(n%2==0){
			For(i,sqrt(n/2)-10,sqrt(n/2)+10)if(i*i*2==n)fl=1;
		}if(n%4==0){
			For(i,sqrt(n/4)-10,sqrt(n/4)+10)if(i*i*4==n)fl=1;
		}puts(fl?"YES":"NO");
	}
	return 0;
}