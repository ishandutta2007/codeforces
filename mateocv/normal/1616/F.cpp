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

void reduce(vector<vector<ll> >& x){ // returns determinant
	if(!SZ(x))return;
	int n=x.size(),m=x[0].size();
	int i=0,j=0;
	while(i<n&&j<m){
		int l=i;
		fore(k,i+1,n)if(abs(x[k][j])>abs(x[l][j]))l=k;
		if(x[l][j]==0){j++;continue;}
		if(l!=i){swap(x[i],x[l]);}
		for(int k=m-1;k>=j;k--)x[i][k]=x[i][k]*x[i][j]%3;
		fore(k,0,n){
			if(k==i)continue;
			for(int l=m-1;l>=j;l--)x[k][l]=(x[k][l]-x[k][j]*x[i][l]+666)%3;
		}
		i++;j++;
	}
}

ll ed[66][66];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> x(m),y(m),w(m);
		mset(ed,-1);
		fore(i,0,m){
			cin>>x[i]>>y[i]>>w[i];
			x[i]--; y[i]--;
			if(w[i]!=-1)w[i]--;
			ed[x[i]][y[i]]=i;
			ed[y[i]][x[i]]=i;
		}				
		vector<vector<ll> > mt;
		fore(i,0,m){
			if(w[i]!=-1){
				vector<ll> v(m+1);
				v[i]++;
				v[m]=w[i];
				mt.pb(v);
			}
		}
		fore(i,0,n){
			fore(j,i+1,n){
				fore(k,j+1,n){
					if(ed[i][j]!=-1&&ed[j][k]!=-1&&ed[k][i]!=-1){
						vector<ll> v(m+1);
						v[ed[i][j]]++;
						v[ed[j][k]]++;
						v[ed[k][i]]++;
						mt.pb(v);
					}
				}
			}
		}
		reduce(mt);
		vector<ll> res(m);
		ll br=0;
		fore(i,0,SZ(mt)){
			ll pos=-1;
			fore(j,0,m+1){
				if(mt[i][j]){
					pos=j;
					break;
				}
			}
			if(pos==m){
				br++;
				break;
			}
			if(pos!=-1){
				res[pos]=mt[i][m];
			}
		}
		if(br)cout<<"-1\n";
		else{
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}