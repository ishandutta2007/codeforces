#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define INF 9187201950435737471LL
using namespace std;

typedef long long ll;

int n,q,a,b;
int v[100005];
int c[100005];
ll f[100005];

ll doit(){
	memset(f,128,sizeof(f));  // sets -INF
	f[0]=0;
	int c1=0,c2=-1;
	fore(i,0,n){
		ll r;
		if(c1!=c[i])r=f[c1]+1LL*b*v[i];
		else {
			assert(c2>=0);
			r=f[c2]+1LL*b*v[i];
		}
		if(f[c[i]]>-INF)r=max(r,f[c[i]]+1LL*a*v[i]);
		if(r>f[c[i]]){
			f[c[i]]=r;
			if(r>f[c1]){
				c2=c1;
				c1=c[i];
			}
			else if(c[i]!=c1&&(c2<0||r>f[c2])){
				c2=c[i];
			}
		}
	}
	ll r=0;
	fore(i,1,n+1)r=max(r,f[i]);
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	fore(i,0,n)cin>>v[i];
	fore(i,0,n)cin>>c[i];
	while(q--){
		cin>>a>>b;
		cout<<doit()<<'\n';
	}
	return 0;
}