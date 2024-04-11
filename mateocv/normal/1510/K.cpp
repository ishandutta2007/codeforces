#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int get(vector<int> &a){
	fore(i,0,SZ(a)) if(a[i]==1) return i;
	assert(0);
}

bool sorted(vector<int> a){
	fore(i,1,SZ(a)) if(a[i]<a[i-1])return 0;
	return 1;
}

int go(vector<int> a, int flag){
	int n=SZ(a);
	vector<int> vis(n);

	fore(it,0,n+1){
		int wh=get(a);
		if(vis[wh]) return -1;
		vis[wh]=1;
		if(wh==0) return sorted(a)?it:-1;
		if(it%2==flag){
			fore(j,0,n/2) swap(a[2*j],a[2*j+1]);
		}
		else{
			fore(j,0,n/2) swap(a[j],a[j+n/2]);
		}
	}
	assert(0);
}

int main(){FIN;
	int n; cin>>n; n*=2;
	vector<int> a(n);
	fore(i,0,n) cin>>a[i];
	int ans=go(a,0);
	int ans2=go(a,1);
	
	if(ans<0) ans=ans2;
	else if(ans2>=0) ans=min(ans,ans2);
	
	cout<<ans<<"\n";
}