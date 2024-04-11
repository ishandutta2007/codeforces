#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll esprimo(ll p){
	if(p==1)return 0;
	for(int i=2;i*i<=p;i++){
		if(p%i==0){
			return 0;
		}
	}
	return 1;
}

/*---------------- Union Find (DSU) ------------------*/
/* Sets up array parent where parent[i] is a member of its
	disjoint set. See DSU file for an example*//*
const int N=3e5+10;
int pa[N],sz[N];
int find_pa(int pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}*/

int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	map<char,ll> mp;
	fore(i,0,n){
		mp[s[i]]++;
	}
//	cout<<mp['a'];
//	dsu_init(n);
/*	fore(i,2,n){
		if(esprimo(i)){
			fore(j,1,n/i){
				join(i,i*j);
			}
		}
	}*/
	ll cant=0, igu[n+1];
	memset(igu,0,sizeof igu);
	fore(i,1,n+1){
		if(2*i<=n||!esprimo(i)){
			igu[i]++;
			if(i==1)igu[1]=0;
		}
		cant+=igu[i];
	}
	ll maxi=0; char maxc='.';
	fore(i,0,26){
		if(mp['a'+i]>maxi){
			maxi=mp['a'+i];
			maxc='a'+i;
		}
	}
	if(maxi>=cant){
		cout<<"YES\n";
		string res=s;
		fore(i,0,n){
			if(igu[i+1])res[i]=maxc;
		}
		mp[maxc]-=cant;
		vector<char> v;
		fore(i,0,26){
			fore(j,0,mp['a'+i]){
				v.pb('a'+i);
			}
		}
	//	fore(i,0,SZ(v))cout<<v[i]<<" "; cout<<"\n";
		fore(i,0,n){
			if(!igu[i+1]){
				res[i]=v.back();
				v.pop_back();
			}
		}
		cout<<res;
	
	}else{
		cout<<"NO";
	}
//	cout<<" "<<maxi<<" "<<cant;
	
	
	return 0;
}