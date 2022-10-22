#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=5005*2,MOD=1e9+7;
int n,m,vis[N];
int s[N],f[N],h[N],L[N],R[N];
vector<int> buc[N];
int cnt[N*3];
signed main() {
	cin>>n>>m;
	fr(i,1,n) {
		cin>>s[i];
		buc[s[i]].push_back(i);
	}
	fr(i,1,m) {
		cin>>f[i]>>h[i];
		if(h[i]<=buc[f[i]].size()) {
			L[i]=buc[f[i]][h[i]-1];
			R[i]=buc[f[i]][buc[f[i]].size()-h[i]];
			vis[L[i]]=i;
		}
	}
	ll ans1=0,ans2=1;
	fr(k,1,n) if(vis[k]) {
		fr(i,1,n) cnt[i]=cnt[i+n]=cnt[i+2*n]=0;
		fr(i,1,m) if(L[i]&&vis[k]!=i) {
			if(L[i]<k&&R[i]>k) ++cnt[f[i]+2*n];
			else if(L[i]<k) ++cnt[f[i]];
			else if(R[i]>k) ++cnt[f[i]+n];
		}
		ll res1=1,res2=1;
		fr(i,1,n) if(f[vis[k]]!=i) {
			ll L=cnt[i],R=cnt[i+n],LR=cnt[i+2*n];
			if(L+LR) {
				if(!LR) {
					if(R) res1+=2,res2=res2*L%MOD*R%MOD;
					else res1+=1,res2=res2*L%MOD;
				} else {
					if(L&&R) res1+=2,res2=((L+LR)*(R+LR)-LR)%MOD*res2%MOD;
					else if(L+R) res1+=2,res2=(L+R+LR-1)*LR%MOD*res2%MOD;
					else if(LR==1) res1+=1,res2=res2*2%MOD;
					else res1+=2,res2=res2*LR%MOD*(LR-1)%MOD;
				}
			} else if(R) res1+=1,res2=res2*R%MOD;
		} else if(cnt[i+n]+cnt[i+2*n]) res1+=1,res2=res2*(cnt[i+n]+cnt[i+2*n])%MOD;
		if(res1>ans1) ans1=res1,ans2=res2;
		else if(res1==ans1) (ans2+=res2)%=MOD;
		//cout<<k<<endl;
		//cout<<ans1<<' '<<(ans2+MOD)%MOD<<endl;
	}
	fr(i,1,n) cnt[i]=0;
	fr(i,1,m) if(R[i]) ++cnt[f[i]];
	ll res1=0,res2=1;
	fr(i,1,n) if(cnt[i]) ++res1,res2=res2*cnt[i]%MOD;
	if(res1>ans1) ans1=res1,ans2=res2;
	else if(res1==ans1) (ans2+=res2)%=MOD;
	if(ans1==0) cout<<"0 1"<<endl;
	else cout<<ans1<<' '<<(ans2+MOD)%MOD<<endl;
	return 0;
}