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

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}

string s; 

vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}

const int K=13;

#define oper min
int st[K][1<<K];  // K such that 2^K>n
void st_init(vector<int> a){
	fore(i,0,SZ(a))st[0][i]=a[i];
	fore(k,1,K)fore(i,0,SZ(a)-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

ll lcp(ll x, ll y){
	return st_query(x,y);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cin>>s;
		s+='a'-1;
		auto sa=constructSA(s);
		/*
		for(auto i:sa)cout<<i<<" ";
		cout<<endl;
		*/
		auto l=computeLCP(s,sa);
		/*
		for(auto i:l)cout<<i<<" ";
		cout<<endl;
		*/
		vector<ll> u(n+1);
		fore(i,0,n+1)u[sa[i]]=i;
		/*
		for(auto i:u)cout<<i<<" ";
		cout<<endl;
		*/
		st_init(l);
		vector<ll> c(SZ(s));
		fore(i,1,SZ(sa)){
			c[sa[i]]=n-sa[i];
			fore(j,0,sa[i]){
				ll l=min(u[j],u[sa[i]])+1;
				ll r=max(u[j],u[sa[i]])+1;
				c[sa[i]]=max(c[sa[i]],c[j]+n-sa[i]-lcp(l,r));
			}
			/*
			for(auto i:c)cout<<i<<" ";
			cout<<endl;
			*/
		}
		ll res=1;
		for(auto i:c)res=max(res,i);
		cout<<res<<"\n";
	}
	
	return 0;
}