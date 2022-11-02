#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef array<array<ll, 2>, 2> mat;
const ll mod=1e9+7;
mat fib;
mat ide;

mat mul(mat a, mat b){
	mat r;
	for (int i=0;i<2;i++){
		for (int ii=0;ii<2;ii++){
			r[i][ii]=0;
			for (int j=0;j<2;j++){
				r[i][ii]+=a[i][j]*b[j][ii];
			}
			r[i][ii]%=mod;
		}
	}
	return r;
}

mat pot(mat a, int p){
	assert(p>0);
	if (p==1) return a;
	if (p%2==0){
		a=pot(a, p/2);
		return mul(a, a);
	}
	else{
		mat b=pot(a, p-1);
		return mul(a, b);
	}
}

void pm(mat t){
	cout<<t[0][0]<<' '<<t[0][1]<<endl;
	cout<<t[1][0]<<' '<<t[1][1]<<endl;
}

const int N=1<<17;
mat st[2*N];
ll su1[2*N];
ll su2[2*N];

void add(int i, int stl, int str, int l, int r, mat x){
	if (stl>r||str<l) return;
	if (l<=stl&&str<=r){
		//cout<<"st0"<<endl;
		//pm(st[i]);
		st[i]=mul(st[i], x);
		//cout<<"st"<<endl;
		//pm(st[i]);
		//cout<<"x"<<endl;
		//pm(x);
		//cout<<"r "<<su1[i]<<" "<<su2[i]<<endl;
		ll ns1=x[0][0]*su1[i]+x[0][1]*su2[i];
		ll ns2=x[1][0]*su1[i]+x[1][1]*su2[i];
		su1[i]=ns1%mod;
		su2[i]=ns2%mod;
		//cout<<"t1 "<<i<<" "<<su1[i]<<" "<<su2[i]<<endl;
	}
	else{
		int m=(stl+str)/2;
		if (st[i]!=ide){
			//cout<<"lz "<<endl;
			//pm(st[i]);
			add(i*2, stl, m, stl, m, st[i]);
			add(i*2+1, m+1, str, m+1, str, st[i]);
			st[i]=ide;
		}
		add(i*2, stl, m, l, r, x);
		add(i*2+1, m+1, str, l, r, x);
		su1[i]=su1[i*2]+su1[i*2+1];
		su2[i]=su2[i*2]+su2[i*2+1];
		su1[i]%=mod;
		su2[i]%=mod;
		//cout<<"t2 "<<i<<" "<<su1[i]<<" "<<su2[i]<<endl;
	}
}

ll sum(int i, int stl, int str, int l, int r){
	if (stl>r||str<l) return 0;
	if (l<=stl&&str<=r){
		return su1[i];
	}
	else{
		int m=(stl+str)/2;
		if (st[i]!=ide){
			add(i*2, stl, m, stl, m, st[i]);
			add(i*2+1, m+1, str, m+1, str, st[i]);
			st[i]=ide;
		}
		ll r1=sum(i*2, stl, m, l, r);
		ll r2=sum(i*2+1, m+1, str, l, r);
		su1[i]=su1[i*2]+su1[i*2+1];
		su2[i]=su2[i*2]+su2[i*2+1];
		su1[i]%=mod;
		su2[i]%=mod;
		return (r1+r2)%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fib[0][0]=1;
	fib[0][1]=1;
	fib[1][0]=1;
	fib[1][1]=0;
	ide[0][0]=1;
	ide[0][1]=0;
	ide[1][0]=0;
	ide[1][1]=1;
	//auto lol=pot(fib, 4);
	//cout<<lol[0][1]<<" "<<lol[1][1]<<endl;
	for (int i=0;i<2*N;i++){
		st[i]=ide;
		su1[i]=0;
		su2[i]=0;
	}
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		st[i+N]=pot(fib, a);
		su1[i+N]=st[i+N][0][1];
		su2[i+N]=st[i+N][1][1];
	}
	for (int i=N-1;i>=1;i--){
		su1[i]=(su1[i*2]+su1[i*2+1])%mod;
		su2[i]=(su2[i*2]+su2[i*2+1])%mod;
	}
	for (int i=0;i<m;i++){
		int t;
		cin>>t;
		if (t==1){
			int l,r,x;
			cin>>l>>r>>x;
			mat fi=pot(fib, x);
			add(1, 0, N-1, l, r, fi);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<sum(1, 0, N-1, l, r)<<'\n';
		}
	}
}