#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		double d; cin>>d;
		if(d==1||d==2||d==3){
			cout<<"N\n";
		}else{
			cout<<"Y ";
			double a=(d+sqrt(d*d-4*d))/2,b=(d-sqrt(d*d-4*d))/2;
			cout<<fixed<<setprecision(15)<<a<<" "<<b<<"\n";
		}
	}
	
	return 0;
}