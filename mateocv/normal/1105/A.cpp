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
	int n; cin>>n;
	int a[n];
	fore(i,0,n) cin>>a[i];
	int res[110],mini=1e9,minid=-1;
	memset(res,0,sizeof res);
	fore(i,1,101){
		fore(j,0,n){
			if(a[j]<i){
				res[i]+=(i-1-a[j]);
			}else if(a[j]>i){
				res[i]+=(a[j]-i-1);
			}
		}
		if(res[i]<mini){
			mini=res[i];
			minid=i;
		}
		
	}
	
	cout<<minid<<" "<<mini;
	
	return 0;
}