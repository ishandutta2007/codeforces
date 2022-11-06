#include <bits/stdc++.h>
#define pb push_back
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
	ll a,b,c,d; cin>>a>>b>>c>>d;
	ll r[n][2],v[n][2];
	fore(i,0,n)cin>>r[i][0]>>r[i][1]>>v[i][0]>>v[i][1];
	long double t[n][2];
	fore(i,0,n){
		if(v[i][0]!=0&&v[i][1]!=0){
			t[i][0]=max(min(1.*(a-r[i][0])/v[i][0],1.*(c-r[i][0])/v[i][0]),min(1.*(b-r[i][1])/v[i][1],1.*(d-r[i][1])/v[i][1]));
			t[i][1]=min(max(1.*(a-r[i][0])/v[i][0],1.*(c-r[i][0])/v[i][0]),max(1.*(b-r[i][1])/v[i][1],1.*(d-r[i][1])/v[i][1]));
		}
		if(v[i][0]==0&&v[i][1]!=0){
			if(r[i][0]<=a||r[i][0]>=c){
				cout<<-1; return 0;
			}
			t[i][0]=min(1.*(b-r[i][1])/v[i][1],1.*(d-r[i][1])/v[i][1]);
			t[i][1]=max(1.*(b-r[i][1])/v[i][1],1.*(d-r[i][1])/v[i][1]);
		}
		if(v[i][0]!=0&&v[i][1]==0){
			if(r[i][1]<=b||r[i][1]>=d){
				cout<<-1; return 0;
			}
			t[i][0]=min(1.*(a-r[i][0])/v[i][0],1.*(c-r[i][0])/v[i][0]);
			t[i][1]=max(1.*(a-r[i][0])/v[i][0],1.*(c-r[i][0])/v[i][0]);
		}
		if(v[i][0]==0&&v[i][1]==0){
			if(r[i][0]<=a||r[i][0]>=c||r[i][1]<=b||r[i][1]>=d){
				cout<<-1; return 0;
			}
			t[i][0]=0;
			t[i][1]=1e18;
		}
	}
	/*fore(i,0,n){
		cout<<fixed<<setprecision(12)<<t[i][0]<<" "<<t[i][1]<<"\n";
	}*/
	long double res=0,tmax=1e19;
	fore(i,0,n){
		if(t[i][0]+1e-10>t[i][1]){
			cout<<-1; return 0;
		}
		res=max(res,t[i][0]);
		tmax=min(tmax,t[i][1]);
	}
	if(res+1e-10>tmax){
		cout<<-1; return 0;
	}
	cout<<fixed<<setprecision(12)<<res;
	return 0;
}