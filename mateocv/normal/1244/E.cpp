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

void dec(deque<pair<ll,ll>> &d, ll c){
	if(c==0)return;
	if(SZ(d)==0)return;
	if(d[SZ(d)-1].fst>c){
		d[SZ(d)-1].fst-=c; return;
	}
	c-=d[SZ(d)-1].fst;
	d.pop_back();
	dec(d,c);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	deque<pair<ll,ll>> d[2];
	fore(i,0,n-1){
		if(a[i]!=a[i+1])d[0].pb({a[i+1]-a[i],i+1});
	}
	reverse(a,a+n);
	fore(i,0,n-1){
		if(a[i]!=a[i+1])d[1].pb({a[i]-a[i+1],i+1});
	}
	reverse(a,a+n);
	/*fore(k,0,2){
		fore(i,0,SZ(d[k]))cout<<d[k][i].fst<<" "<<d[k][i].snd<<"\n";
	}*/
	/*while(SZ(d[0])){
		dec(d[0],1);
		fore(i,0,SZ(d[0]))cout<<d[0][i].fst<<" "<<d[0][i].snd<<"\n";
		cout<<"\n";
	}*/
	//return 0;
	ll dif=a[n-1]-a[0];
	while(k>0){
		if(SZ(d[0])==0||SZ(d[1])==0)break;
		if(d[0][0].snd<d[1][0].snd){
			ll cant=min(d[0][0].fst,k/d[0][0].snd);
			if(cant==0)break;
			dif-=cant;
			k-=cant*d[0][0].snd;
			if(cant==d[0][0].fst){
				d[0].pop_front();
				dec(d[1],cant);
			}else{
				d[0][0].fst-=cant;
				dec(d[1],cant);
			}
		}else{
			ll cant=min(d[1][0].fst,k/d[1][0].snd);
			if(cant==0)break;
			dif-=cant;
			k-=cant*d[1][0].snd;
			if(cant==d[1][0].fst){
				d[1].pop_front();
				dec(d[0],cant);
			}else{
				d[1][0].fst-=cant;
				dec(d[0],cant);
			}
		}
	}
	cout<<dif;
	return 0;
}