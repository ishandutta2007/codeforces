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

ll n;
ll a[505],b[505];
ll ok[505];

vector<ll> res;

void oper(ll i){
	assert(i<n-2);
	swap(a[i+1],a[i+2]);
	swap(a[i],a[i+1]);
}

void movr(ll i){
	//cout<<"r "<<i<<": "<<endl;
	assert(i>=2);
	ll s=-1;
	fore(j,0,n){
		if(a[n-1-j]==b[i]&&!ok[n-1-j]){
			s=n-1-j;
			break;
		}
	}
	assert(s!=-1);
	fore(j,s-1,i-1){
		if(j==-1)res.pb(0),oper(0);
		else res.pb(j),oper(j);
		//cout<<j<<" ";
	}
	//cout<<"\n";
	ok[i]++;
}

void movl(ll i){
	//cout<<"l "<<i<<endl;
	assert(i<n-2);
	ll s=-1;
	fore(j,0,n){
		if(a[j]==b[i]&&!ok[j]){
			s=j;
			break;
		}
	}
	ll pos=s;
	assert(s!=-1);
	while(pos>i){
		if(pos-2==-1||ok[pos-2]){
			res.pb(pos-1); res.pb(pos-1);
			oper(pos-1); oper(pos-1);
			pos=pos-1;
		}else{
			res.pb(pos-2);
			oper(pos-2);
			pos-=2;	
		}
	}
	if(pos<i){
		res.pb(pos);
		oper(pos);
	}
	ok[i]++;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i],b[i]=a[i];
		sort(b,b+n);
		ll s=-1;
		fore(i,0,n-1){
			if(b[i]==b[i+1])s=i;
		}
		if(s==-1)s=0;
		fore(i,0,n)ok[i]=0;
		fore(i,0,n){
			//cout<<n-1-i<<":\n";
			if(n-1-i>s+1){
				movr(n-1-i);
				//fore(j,0,n)cout<<a[j]<<" "; cout<<"\n";
			}
		}
		fore(i,0,n){
			//cout<<i<<":\n";
			if(i<s){
				movl(i);
				//fore(j,0,n)cout<<a[j]<<" "; cout<<"\n";
			}
		}
		ll tot=0;
		fore(i,0,n)tot+=(a[i]==b[i]);
		assert(tot>=n-2);
		if(tot==n){
			cout<<SZ(res)<<"\n";
			assert(SZ(res)<=n*n);
			for(auto i:res)cout<<i+1<<" "; cout<<"\n";
		}else{
			cout<<-1<<"\n";
		}
		res.clear();
	}
	
	return 0;
}