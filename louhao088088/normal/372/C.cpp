#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,k,x,y,d,f[2][maxn],t[maxn],sum,tot=0;
signed s[305][maxn];
deque<pi>q;vector<int>g;
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),d=read();
	for(int i=1;i<=m;i++){
		y=read(),x=read(),t[i]=read();sum+=x;
		if(t[i]!=t[i-1]){
			if(g.size()){
				int o=g.size();t[tot]=t[i-1];
				for(int k=1;k<=n;k++)
					for(auto j:g)s[tot][k]=s[tot][k]+abs(j-k);
			}
			g.clear();
			tot++;g.pb(y);
		}else g.pb(y);
	}
	if(g.size()){
		int o=g.size();t[tot]=t[m];
			for(int k=1;k<=n;k++)
				for(auto j:g)s[tot][k]=s[tot][k]+abs(j-k);
	}int now=1,lst=0;
	for(int i=1;i<=n;i++)f[now][i]=s[1][i];
	for(int i=2;i<=tot;i++){
		swap(now,lst);memset(f[now],0x3f,sizeof f[now]);int r=0;
		while(!q.empty())q.pop_back();
		for(int j=1;j<=n;j++){
			int z=(t[i]-t[i-1])*d;
			while(r<n&&r<j+z){r++;
				while(!q.empty()&&f[lst][r]<=q.back().fi)q.pop_back();
				q.push_back(mp(f[lst][r],r));
			}
			while(!q.empty()&&q.front().se<j-z)q.pop_front();
			if(q.size())f[now][j]=q.front().fi+s[i][j];
		//	cout<<f[now][j]<<" "<<i<<" "<<j<<" "<<r<<" "<<q.size()<<" "<<q.front().se<<" "<<z<<" "<<t[i]<<" "<<t[i-1]<<endl;
		}
	}int ans=1e9;
	for(int i=1;i<=n;i++)ans=min(ans,f[now][i]);
	cout<<sum-ans<<endl;
 	return 0;
}