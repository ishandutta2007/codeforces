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

const int MAXN = 1000006;

ll a[MAXN];

pair<ll,ll> p[MAXN];

vector<vector<ll>> v;

vector<ll> va;
bool vis[MAXN];

set<ll> st;

int main(){FIN;
	ll n; cin>>n;
	if(n%2==0){
		cout<<"First"<<endl;
		fore(i,0,n){
			cout<<i+1<<" ";
		}
		fore(i,0,n){
			cout<<i+1<<" ";
		}
		cout<<endl;
		ll resp; cin>>resp;
		return 0;
	}else{
		cout<<"Second"<<endl;
		fore(i,0,2*n)cin>>a[i],a[i]--;
		mset(p,-1);
		fore(i,0,2*n){
			if(p[a[i]].fst==-1){
				p[a[i]].fst=i;
			}else{
				p[a[i]].snd=i;
			}
		}
		fore(i,0,2*n){
			if(vis[i])continue;
			va.pb(i);
			va.pb(p[a[i]].fst^p[a[i]].snd^i);
			vis[i]=1;
			vis[va.back()]=1;
			ll nx=(va.back()+n)%(2*n);
			while(!vis[nx]){
				va.pb(nx);
				va.pb(p[a[nx]].fst^p[a[nx]].snd^nx);
				vis[nx]=1;
				vis[va.back()]=1;
				nx=(va.back()+n)%(2*n);
			}
			v.pb(va);
			va.clear();
		}
		fore(i,0,SZ(v)){
			fore(j,0,SZ(v[i])){
				if(j&1)st.insert(v[i][j]);
			}
		}
		ll sum=0;
		for(auto i:st)sum+=i+1;
		if(sum%(2*n)==0){
			for(auto i:st)cout<<i+1<<" ";
			cout<<endl;
		}else{
			ll br=0;
			fore(i,0,SZ(v)){
				if((SZ(v[i])/2)&1){
					fore(j,0,SZ(v[i])){
						if(j&1){
							st.erase(v[i][j]);
						}else{
							st.insert(v[i][j]);
						}
					}
					br++;
					break;
				}
			}
			assert(br);
			for(auto i:st)cout<<i+1<<" ";
			cout<<endl;
		}
		ll resp; cin>>resp;
		return 0;
	}
	
	return 0;
}