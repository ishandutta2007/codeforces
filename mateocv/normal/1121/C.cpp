#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k; cin>>n>>k;
	queue<ll> q; ll lle;
	fore(i,0,n){
		cin>>lle;
		q.push(lle);
	}
	ll tot=0,por=0,res=0,lin[k];
	pair<ll,ll> t[k];
	memset(t,0,sizeof t);
	memset(lin,0,sizeof lin);
	fore(i,0,1500005){
		fore(j,0,k){
			if(t[j].fst==t[j].snd){
				if(t[j].fst!=0){
					tot++; por=(200*tot+n)/(2*n);
				}
				t[j].fst=0; lin[j]=0;
				if(SZ(q)){
					t[j].snd=q.front(); q.pop();
				}else{
					t[j].snd=-1;
				}
			}
		}
		fore(j,0,k){
			if(t[j].snd!=-1)t[j].fst++;
		}
		fore(j,0,k){
			if(t[j].fst==por&&por!=0){
				if(!lin[j]){
					res++; lin[j]++;
					//cout<<j<<" "<<por<<"\n";
				}
			}
		}
	}
	cout<<res;
	
	return 0;
}