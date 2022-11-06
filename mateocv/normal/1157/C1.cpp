#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	deque<ll> d;
	ll l;
	fore(i,0,n){
		cin>>l; d.pb(l);
	}
	ll res=0,last=0;
	string s;
	while(d.back()!=d.front()){
		if(d.back()<d.front()){
			if(d.back()>last){
				res++; s+='R'; last=d.back(); d.pop_back();	
			}else if(d.front()>last){
				res++; s+='L'; last=d.front(); d.pop_front();
			}else break;
		}else{
			if(d.front()>last){
				res++; s+='L'; last=d.front(); d.pop_front();
			}else if(d.back()>last){
				res++; s+='R'; last=d.back(); d.pop_back();	
			}else break;
		}
	}
	if(SZ(d)==1){
		if(d.back()>last){
			res++; s+='R'; last=d.back(); d.pop_back();	
		}
	}else{
		ll con1=0,con2=0,last1=last,last2=last;
		fore(i,0,SZ(d)){
			if(d[i]>last1){
				last1=d[i];
				con1++;
			}else break;
		}
		for(int i=SZ(d)-1;i>=0;i--){
			if(d[i]>last2){
				last2=d[i];
				con2++;
			}else break;
		}
		if(con1>con2){
			while(con1--){
				res++; s+='L'; last=d.front(); d.pop_front();
			}
		}else{
			while(con2--){
				res++; s+='R'; last=d.back(); d.pop_back();	
			}
		}
	}
	cout<<res<<"\n"<<s;
	
	return 0;
}