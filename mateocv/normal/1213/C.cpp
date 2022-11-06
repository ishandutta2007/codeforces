    #include <bits/stdc++.h>
    #define pb push_back
    #define fst first
    #define snd second
    #define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
    #define SZ(x) ((int)x.size())
    #define ALL(x) x.begin(),x.end()
    #define mset(a,v) memset((a),(v),sizeof(a))
    #define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    using namespace std;
    typedef long long ll;
     
     
    int main(){FIN;
    	ll q; cin>>q;
    	while(q--){
    	    ll n,m; cin>>n>>m;
    	    vector<ll> v;
    	    fore(i,1,12){
    	        ll br=0;
    	        fore(j,0,SZ(v)){
    	            if(v[j]%10==(i*m)%10){
    	                br++; break;
    	            }
    	        }
    	        if(!br)v.pb(i*m);
    	    }
    	    //fore(i,0,SZ(v))cout<<v[i]<<" "; cout<<"\n";
    	    ll res=0;
    	    fore(j,0,SZ(v)){
    	        if(n<(j+1)*m)continue;
    	        //cout<<(((n-m*((j+1)%SZ(v))))/(SZ(v)*m)+1)*(v[j]%10)<<" ";
    	        res+=(((n-m*((j+1)%SZ(v))))/(SZ(v)*m)+1)*(v[j]%10);
    	    }
    	   // cout<<"\n";
    	    cout<<res<<"\n";
    	}
    	return 0;
    }