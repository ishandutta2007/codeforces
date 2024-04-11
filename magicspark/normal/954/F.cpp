#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
const int N=1e5+10;
const int mod=1e9+7;
typedef vector<vector<int> > mat;
inline void init(mat&res,int n,int m){
	res.resize(n+1);
	for(int i=1;i<=n;i++)res[i].resize(m+1,0);
}
inline mat Get1(){
	mat res;init(res,3,3);
	for(int i=1;i<=3;i++)res[i][i]=1;
	return res;
}
inline mat operator*(const mat&A,const mat&B){
	int n=A.size()-1,m=A[1].size()-1,k=B[1].size()-1;
//	cerr<<n<<","<<m<<","<<k<<endl;
	mat res;init(res,n,k);
	for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)for(int l=1;l<=m;l++)
		res[i][j]=(res[i][j]+1ll*A[i][l]*B[l][j]%mod)%mod;
	return res;
}
inline mat ksm(mat A,ll k){
	if(k==0)return Get1();
	mat res=ksm(A,k>>1);
	res=res*res;
	if(k&1)res=res*A;
	return res;
}
int n;ll m;
vector<ll>pt;
map<ll,vector<int> >add,del;
int cnt[4];
signed main(){
	scanf("%lld%lld",&n,&m);
	pt.pb(1);pt.pb(m+1);pt.pb(m);
	for(int i=1;i<=n;i++){
		int pos;ll l,r;
		scanf("%lld%lld%lld",&pos,&l,&r);
		add[l].pb(pos);
		del[r+1].pb(pos);
		pt.pb(l);pt.pb(r+1);
	}
	sort(pt.begin(),pt.end());
	pt.erase(unique(pt.begin(),pt.end()),pt.end());
//	for(auto i:pt)cerr<<i<<" ";cerr<<endl;
	mat res;init(res,1,3);res[1][2]=1;
	for(int i=0;i+1<(int)pt.size();i++){			
		for(auto x:add[pt[i]])cnt[x]++;
		for(auto x:del[pt[i]])cnt[x]--;
		mat mt;init(mt,3,3);
		for(int j=1;j<=3;j++){
			if(cnt[j]){
				res[1][j]=0;
			}
			if(!cnt[j])mt[j][j]++;
			if(1<=j-1&&!cnt[j])mt[j][j-1]++;
			if(j+1<=3&&!cnt[j])mt[j][j+1]++;
		}
//		for(int j=1;j<=3;j++)cerr<<res[1][j]<<" ";cerr<<endl;
//		for(int i=1;i<=3;i++){
//			for(int j=1;j<=3;j++)cerr<<mt[i][j]<<" ";
//			cerr<<endl;
//		}
//		cerr<<endl;
		mt=ksm(mt,pt[i+1]-pt[i]);
//		for(int i=1;i<=3;i++){
//			for(int j=1;j<=3;j++)cerr<<mt[i][j]<<" ";
//			cerr<<endl;
//		}
//		cerr<<endl;
		if(i+1!=(int)pt.size()-1)res=res*mt;
	}
	printf("%d\n",res[1][2]);
	return 0;
}
/*inline? ll or int? size? min max?*/