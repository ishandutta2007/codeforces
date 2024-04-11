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

string res;

void run(ll a, ll b, ll c, ll d, ll s){
	if(a==0&&b==0&&c==0&&d==0)return;
	if(s==0){
		if(a>0){
			res.pb('0');
			run(a-1,b,c,d,1);
		}else{
			res.pb('.'); return;
		}
	}else if(s==3){
		if(d>0){
			res.pb('3');
			run(a,b,c,d-1,2);
		}else{
			res.pb('.'); return;
		}
	}else if(s==1){
		if(b>0){
			res.pb('1');
			if(a>0){
				run(a,b-1,c,d,0);
			}else{
				run(a,b-1,c,d,2);
			}
		}else{
			res.pb('.'); return;
		}
	}else if(s==2){
		if(c>0){
			res.pb('2');
			if(d>0){
				run(a,b,c-1,d,3);
			}else{
				run(a,b,c-1,d,1);
			}
		}else{
			res.pb('.'); return;
		}
	}
}

int main(){FIN;
	ll a,b,c,d; cin>>a>>b>>c>>d;
	if(abs(a+c-b-d)>1){
		cout<<"NO"; return 0;
	}
	fore(k,0,4){
		run(a,b,c,d,k);
		if(res.back()!='.'){
			cout<<"YES\n";
			fore(i,0,SZ(res))cout<<res[i]<<" ";
			return 0;
		}
		res.clear();
	}
	cout<<"NO";
	return 0;
}