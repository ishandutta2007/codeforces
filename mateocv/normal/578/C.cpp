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
ll a[200006];

double f(double x){
	double b[n];
	fore(i,0,n)b[i]=a[i]-x;
	double res[2]={0,0},va[2]={0,0};
	fore(i,0,n){
		va[0]=max(va[0]+b[i],b[i]);
		res[0]=max(res[0],va[0]);
		va[1]=min(va[1]+b[i],b[i]);
		res[1]=min(res[1],va[1]);
	}
	return max(abs(res[0]),abs(res[1]));
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	double l=-1e11,r=1e11;
	ll it=200;
	while(it--){
		//cout<<l<<" "<<r<<"\n";
		double m1=l+(r-l)/3,m2=r-(r-l)/3;
		if(f(m1)>f(m2))l=m1;
		else r=m2;
	}
	cout<<fixed<<setprecision(15)<<f((l+r)/2);
	
	return 0;
}