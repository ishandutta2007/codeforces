#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=200009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,w,k,a[N];
vector <int> ans;

signed main() {
	T=read();
	while(T--) {
		n=read(), w=read();
		k=(w+1)/2;
		rep(i,1,n) a[i]=read();
		ans.clear();
		int sum=0;
		bool flg=0;
		rep(i,1,n) {
			if(a[i]>w) continue;
			if(sum+a[i]>w) {
				ans.clear();
				ans.push_back(i);
				flg=1;
				break;
			}
			sum+=a[i];
			ans.push_back(i);
			if(sum>=k) {
				flg=1;
				break;
			}
		}
		if(!flg) puts("-1");
		else {
			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
			puts("");
		}
	}
	return 0;
}