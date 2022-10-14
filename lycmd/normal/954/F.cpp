#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=23333,MOD=1000000007;
int n,m,l[N],r[N],p[N],s[5],cnt[5][N];
vector<int>b; 
struct matrix{
	static int const N=3;
	int v[N][N];
	matrix(){
		memset(v,0,sizeof v);
	}
	matrix(const array<int,N*N>&a){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				v[i][j]=a[i*N+j];
	}
	int*operator[](int x){
		return v[x];
	}
	const int*operator[](int x)const{
		return v[x];
	}
	matrix operator*(const matrix&rhs)const{
		matrix res;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
					res[i][j]=(res[i][j]+v[i][k]*rhs[k][j]%MOD)%MOD;
		return res;
	}
	matrix qpow(int y){
		matrix ans,t=*this;
		for(int i=0;i<N;i++)
			ans[i][i]=1;
		for(;y;y>>=1,t=t*t)
			if(y&1)ans=ans*t;
		return ans;
	}
};
matrix ans,t;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	b.push_back(1),b.push_back(m);
	for(int i=1;i<=n;i++)
		cin>>p[i]>>l[i]>>r[i],
		b.push_back(l[i]-1),b.push_back(r[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++)
		cnt[p[i]][lower_bound(b.begin(),b.end(),l[i])-b.begin()]++,
		cnt[p[i]][lower_bound(b.begin(),b.end(),r[i])-b.begin()+1]--;
	ans[1][0]=1;
	for(int i=1;i<b.size();i++){
		t=matrix({1,1,0,1,1,1,0,1,1});
		for(int j=0;j<3;j++)
			if(s[j]+=cnt[j+1][i])
				t[j][0]=t[j][1]=t[j][2]=0;
		ans=t.qpow(b[i]-b[i-1])*ans;
	}
	cout<<ans[1][0]<<"\n";
}