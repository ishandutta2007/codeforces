#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=110;
int n,m,ans,a[N],b[N],cnt[2];
std::vector<int> q[2];
int solve(){
	int ans=0;
	m=0,cnt[0]=n>>1,cnt[1]=(n+1)>>1;
	q[0].clear();
	q[1].clear();
	for(int i=1;i<=n;i++)if(~a[i])cnt[a[i]]--;
	for(int i=0;i<=n+1;i++)if(~a[i])b[++m]=i;
	for(int i=1;i<m;i++)if(a[b[i]]!=a[b[i+1]])ans++;
	for(int i=1;i<m;i++)if(a[b[i]]==a[b[i+1]]){
		q[a[b[i]]].push_back(b[i+1]-b[i]-1);
	}
	std::sort(q[0].begin(),q[0].end());
	std::sort(q[1].begin(),q[1].end());
	for(int i=0;i<q[0].size();i++){
		if(q[0][i]<=cnt[0])cnt[0]-=q[0][i];
		else ans+=2;
	}
	for(int i=0;i<q[1].size();i++){
		if(q[1][i]<=cnt[1])cnt[1]-=q[1][i];
		else ans+=2;
	}
	return ans;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int x,i=1;i<=n;i++)read(x),a[i]=x?x&1:-1;
	ans=n;
	a[0]=0,a[n+1]=0,ans=std::min(ans,solve());
	a[0]=0,a[n+1]=1,ans=std::min(ans,solve());
	a[0]=1,a[n+1]=0,ans=std::min(ans,solve());
	a[0]=1,a[n+1]=1,ans=std::min(ans,solve());
	printf("%d\n",ans);
}