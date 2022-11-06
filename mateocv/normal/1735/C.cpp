#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=27;
int pa[MAXN],sz[MAXN],l[MAXN],r[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x,r[x]=r[y];
		else sz[y]+=sz[x],pa[x]=y,l[y]=l[x];
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1,l[i]=i,r[i]=i;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		dsu_init(26);
		ll ne[MAXN];
		ll av[MAXN];
		mset(ne,-1);
		fore(i,0,MAXN)av[i]=1;
		string res(SZ(s),'.');
		fore(i,0,n){
			ll ch=s[i]-'a';
			if(ne[ch]!=-1){
				res[i]='a'+ne[ch];
			}else{
				if(sz[find_pa(0)]!=26){
					fore(j,0,26){
						if(ch!=j&&av[j]&&find_pa(ch)!=find_pa(j)){
							ne[ch]=j;
							av[j]=0;
							join(ch,j);
							break;
						}
					}
				}else{
					fore(j,0,26){
						if(ch!=j&&av[j]){
							ne[ch]=j;
							av[j]=0;
							break;
						}
					}
				}
				res[i]='a'+ne[ch];
			}
		}
		//fore(i,0,26)cout<<ne[i]<<" ";
		//cout<<"\n";
		cout<<res<<"\n";
	}
	
	return 0;
}