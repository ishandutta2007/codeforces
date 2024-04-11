//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const ll P=1000000000000000000;const int N=600005;
map<int,int>mp;int n,nxt[N],T[N<<2],cl[N];char s[N],tg[5];
int st[N],tp,w[N],fa[N][26];ll nwv=0;
struct node
{
	ll a,b;inline ll operator%(const ll &p) const {return (a%p+P%p*b%p)%p;}
	inline node operator+(const ll &w) const {return(node){(a+w)%P,b+(a+w)/P};}
	inline void write() {if(b) printf("%lld%018lld\n",b,a);else printf("%lld\n",a);}
}ans;
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x]=dc,void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 2e9+5;else if(dl<=l&&r<=dr) return T[x];
	return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
inline void add(int x,int w) {nwv+=1ll*x*w,mp[x]+=w;}
inline int update(int x)
{
	int cnt=0;tp=0;
	for(map<int,int>::iterator i=mp.upper_bound(x);i!=mp.end();i++)
		st[++tp]=i->first,cnt+=i->second,nwv-=1ll*i->first*i->second;
	while(tp) mp.erase(st[tp--]);
	return cnt;
}
int main()
{
	read(n),scanf("%s",tg),read(w[1]),s[1]=*tg-'a';
	modif(1,1,n,1,w[1]),ans=ans+w[1],ans.write();
	for(int i=2;i<=n;i++)
	{
		scanf("%s",tg),read(w[i]);s[i]=(*tg-'a'+ans%26)%26,w[i]^=ans%(1<<30);
		int k=nxt[i-1];if(s[i]==s[1]) add(w[i],1);
		modif(1,1,n,i,w[i]),ans=ans+query(1,1,n,1,i);
		while(k&&s[k+1]!=s[i]) k=nxt[k];
		nxt[i]=k+(s[k+1]==s[i]),cl[i-1]=s[i];
		for(int j=0;j<26;j++) fa[i][j]=fa[nxt[i]][j];
		fa[i][cl[nxt[i]]]=nxt[i];
		for(int c=0;c<26;c++) if(c^s[i]) for(int j=fa[i-1][c];j;j=fa[j][c]) add(query(1,1,n,i-j,i-1),-1);
		add(w[i],update(w[i])),ans=ans+nwv,ans.write();
	}
	return 0;
}