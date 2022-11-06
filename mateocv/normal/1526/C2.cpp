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
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	ll va=0,res=0;
	priority_queue<ll> pq;
	for(auto i:a){
		if(i>=0){
			va+=i;
			res++;
		}else{
			if(va+i>=0){
				va+=i;
				res++;
				pq.push(-i);
			}else{
				if(SZ(pq)&&pq.top()>abs(i)){
					ll t=pq.top(); pq.pop();
					va+=t;
					va+=i;
					pq.push(-i);
				}
			}
		}
	}
	cout<<res<<"\n";
	
	return 0;
}