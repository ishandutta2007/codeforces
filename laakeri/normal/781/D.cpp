#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const int SZ=510;
typedef array<bitset<SZ>, SZ> mat;

const ll inf=1e18;

mat trp(const mat& a){
	mat ret;
	for (int i=0;i<SZ;i++){
		for (int ii=0;ii<SZ;ii++){
			ret[i][ii]=a[ii][i];
		}
	}
	return ret;
}

mat mul(const mat& a, const mat& b){
	mat r;
	mat tb=trp(b);
	for (int i=0;i<SZ;i++){
		for (int ii=0;ii<SZ;ii++){
			r[i][ii]=0;
			bitset<SZ> x=a[i]&tb[ii];
			r[i][ii]=(x.count()>0);
		}
	}
	return r;
}

int has1(const mat& t){
	if (t[1].count()>0) return 1;
	return 0;
}

mat pm[70];
mat vm[70];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<SZ;i++){
		for (int ii=0;ii<SZ;ii++){
			pm[0][i][ii]=0;
			vm[0][i][ii]=0;
		}
	}
	for (int i=0;i<m;i++){
		int v,u,t;
		cin>>v>>u>>t;
		if (t==0){
			pm[0][v][u]=1;
		}
		else{
			vm[0][v][u]=1;
		}
	}
	for (int i=1;i<=60;i++){
		pm[i]=mul(pm[i-1], vm[i-1]);
		vm[i]=mul(vm[i-1], pm[i-1]);
	}
	if (has1(pm[60])){
		cout<<-1<<endl;
		return 0;
	}
	if (!has1(pm[0])){
		cout<<0<<endl;
		return 0;
	}
	int t=0;
	ll v=0;
	mat y;
	for (int i=59;i>=0;i--){
		if (has1(pm[i])){
			t=i;
			v=(1ll<<(ll)i);
			y=pm[i];
			break;
		}
	}
	int k=1;
	for (int j=t-1;j>=0;j--){
		mat x;
		if (k==1){
			x=mul(y, vm[j]);
		}
		else{
			x=mul(y, pm[j]);
		}
		if (has1(x)){
			v+=(1ll<<(ll)j);
			k^=1;
			y=x;
		}
	}
	if (v>inf){
		cout<<-1<<endl;
		return 0;
	}
	cout<<v<<endl;
}