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

map<ll,ll> mp;
ll vis2[100005];
vector<ll> dos,tres;
vector<pair<ll,ll>> res;

ll vis[100005];

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll ult=-1;
	fore(i,0,n){
		if(a[i])ult=a[i];
	}
	if(ult==-1){
		cout<<"0\n";
		return 0;
	}
	if(ult==2||ult==3){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n){
		if(a[i]==2)dos.pb(i);
		else if(a[i]==1&&SZ(dos)){
			mp[dos.back()]=i;
			dos.pop_back();
			vis2[i]=1;
		}
	}
	fore(i,0,n){
		if(SZ(tres)&&!vis2[i]&&a[i]!=0){
			mp[tres.back()]=i;
			tres.pop_back();
		}
		if(a[i]==3)tres.pb(i);
	}
	if(SZ(dos)||SZ(tres)){
		cout<<"-1\n";
		return 0;
	}
	mset(vis,-1);
	ll us=0;
	fore(i,0,n){
		if(a[i]==0)continue;
		if(a[i]==1){
			if(vis[i]!=-1)continue;
			res.pb({us,i});
			vis[i]=us;
			us++;
		}
		if(a[i]==2){
			if(vis[i]!=-1){
				res.pb({vis[i],mp[i]});
				vis[mp[i]]=i;
			}else{
				res.pb({us,i});
				res.pb({us,mp[i]});
				vis[mp[i]]=us;
				us++;
			}
		}
		if(a[i]==3){
			if(vis[i]!=-1){
				res.pb({vis[i],mp[i]});
				res.pb({us,mp[i]});
				vis[mp[i]]=us;
				us++;
			}else{
				res.pb({us,i});
				res.pb({us,mp[i]});
				vis[mp[i]]=us;
				us++;
				res.pb({us,mp[i]});
				vis[mp[i]]=us;
				us++;
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}