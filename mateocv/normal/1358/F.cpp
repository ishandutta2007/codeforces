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

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	string res;
	if(n==1){
		if(a[0]==b[0]){
			cout<<"SMALL\n0";
		}else{
			cout<<"IMPOSSIBLE";
		}
		return 0;
	}else if(n==2){
		ll rev=0;
		if(a[0]>a[1]){
			swap(a[0],a[1]);
			rev++;
		}
		vector<ll> r;
		while(1){
			//cout<<b[0]<<" "<<b[1]<<"\n";
			if(a[0]==b[0]&&b[1]>=a[1]&&(b[1]-a[1])%b[0]==0){
				//for(auto i:r)cout<<i<<" "; cout<<"\n";
				if((b[1]-a[1])/b[0]>0)r.pb((b[1]-a[1])/b[0]);
				ll tot=0,tot2=0;
				for(auto i:r){
					if(i==0)tot++;
					else tot+=i,tot2+=i;
				}
				if(tot2<=200000){
					cout<<"SMALL\n";
					reverse(ALL(r));
					if(rev)res.pb('R');
					for(auto i:r){
						if(i==0)res.pb('R');
						else fore(j,0,i)res.pb('P');
					}
					reverse(ALL(res));
					if(SZ(res)>=2&&res[SZ(res)-1]=='R'&&res[SZ(res)-2]=='R'){
						res.pop_back(); res.pop_back();
					}
					reverse(ALL(res));
					cout<<SZ(res)<<"\n"<<res;
					return 0;
				}else{
					cout<<"BIG\n";
					cout<<tot2;
					return 0;
				}
				//cout<<"MALLLLLL";
				return 0;
			}
			if(b[1]<b[0]){
				reverse(b,b+n);
				r.pb(0);
			}else{
				r.pb((b[1]-b[1]%b[0])/b[0]);
				b[1]=b[1]%b[0];
			}
			if(b[0]<=0||b[1]<=0){
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	}else{
		ll rev=0;
		if(a[0]>a[n-1]){
			reverse(a,a+n);
			rev++;
		}
		while(1){
			ll tot=0;
			fore(i,0,n)tot+=(a[i]==b[i]);
			if(tot==n){
				ll op=0;
				fore(i,0,SZ(res))op+=(res[i]=='P');
				if(op<=200000){
					cout<<"SMALL\n";
					if(rev)res.pb('R');
					if(SZ(res)>=2&&res[SZ(res)-1]=='R'&&res[SZ(res)-2]=='R'){
						res.pop_back(); res.pop_back();
					}
					reverse(ALL(res));
					cout<<SZ(res)<<"\n"<<res;
					return 0;	
				}else{
					cout<<"BIG\n";
					cout<<op;
					return 0;
				}	
			}else{
				fore(i,0,n){
					if(b[i]<=0){
						cout<<"IMPOSSIBLE";
						return 0;
					}
				}
			}
			if(b[n-1]<=b[0]){
				reverse(b,b+n);
				res+='R';
				if(SZ(res)>=2&&res[SZ(res)-1]=='R'&&res[SZ(res)-2]=='R'){
					cout<<"IMPOSSIBLE";
					return 0;
				}
			}else{
				fore(i,0,n-1){
					b[n-1-i]-=b[n-2-i];
				}
				res+='P';
			}	
		}
		
	}
	return 0;
}