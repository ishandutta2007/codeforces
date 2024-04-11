#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

int n,m,ans,tot,s[100009];
pii a[100009];

signed main() {
	int T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,m) {
			a[i].fi=read(), a[i].se=read();
		}
		sort(a+1,a+m+1); reverse(a+1,a+m+1);
		rep(i,1,m) s[i]=s[i-1]+a[i].fi;
		ans=0;
		rep(i,1,m) {
			int l=1,r=m,pos=0;
			while(l<=r) {
				int mid=(l+r)>>1;
				//cout<<"	"<<mid<<" "<<a[mid].fi<<" "<<a[i].se<<endl;
				if(a[mid].fi>=a[i].se) pos=mid, l=mid+1;
				else r=mid-1;
			}
			//cout<<i<<" "<<pos<<" "<<a[i].fi<<endl;
			if(pos>=n) ans=max(ans,s[n]);
			else if(pos<i) ans=max(ans,s[pos]+a[i].fi+a[i].se*(n-pos-1));
			else ans=max(ans,s[pos]+a[i].se*(n-pos));
		}
		printf("%lld\n",ans);
	}
	return 0;
}