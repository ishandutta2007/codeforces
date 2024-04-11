#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;
const ld PI=atan2(0, -1);

const int N=1<<19;

co st[2*N];
int is[2*N][2];
co lz[2*N][2];

void add(int, int, int, int, int, co);
void mul(int, int, int, int, int, co);

void golazy(int i, int l, int r){
	int m=(l+r)/2;
	if (is[i][1]){
		mul(i*2, l, m, l, m, lz[i][1]);
		mul(i*2+1, m+1, r, m+1, r, lz[i][1]);
		is[i][1]=0;
		lz[i][1]={1, 0};
	}
	if (is[i][0]){
		add(i*2, l, m, l, m, lz[i][0]),
		add(i*2+1, m+1, r, m+1, r, lz[i][0]);
		is[i][0]=0;
		lz[i][0]={0, 0};
	}
}

void add(int i, int stl, int str, int l, int r, co v){
	if (stl>r||str<l) return;
	if (l<=stl&&str<=r){
		st[i]+=v;
		is[i][0]=1;
		lz[i][0]+=v;
	}
	else{
		golazy(i, stl, str);
		int m=(stl+str)/2;
		add(i*2, stl, m, l, r, v);
		add(i*2+1, m+1, str, l, r, v);
	}
}

void mul(int i, int stl, int str, int l, int r, co v){
	if (stl>r||str<l) return;
	if (l<=stl&&str<=r){
		st[i]*=v;
		lz[i][0]*=v;
		is[i][1]=1;
		lz[i][1]*=v;
	}
	else{
		golazy(i, stl, str);
		int m=(stl+str)/2;
		mul(i*2, stl, m, l, r, v);
		mul(i*2+1, m+1, str, l, r, v);
	}
}

co get(int i, int stl, int str, int x){
	if (stl==str){
		return st[i];
	}
	else{
		golazy(i, stl, str);
		int m=(stl+str)/2;
		if (x<=m){
			return get(i*2, stl, m, x);
		}
		else{
			return get(i*2+1, m+1, str, x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<2*N;i++){
		lz[i][1]={1, 0};
	}
	for (int i=1;i<=n+1;i++){
		st[N+i]={(ld)(i-1), 0};
	}
	for (int qq=0;qq<m;qq++){
		int x,y,z;
		cin>>x>>y>>z;
		if (x==1){
			co p1=get(1, 0, N-1, y);
			co p2=get(1, 0, N-1, y+1);
			co u=((p2-p1)/abs(p2-p1))*(ld)z;
			add(1, 0, N-1, y+1, n+1, u);
		}
		if (x==2){
			co A=get(1, 0, N-1, y);
			co a=polar((ld)1, -((ld)z/(ld)180*PI));
			mul(1, 0, N-1, y+1, n+1, a);
			add(1, 0, N-1, y+1, n+1, -(A*a)+A);
		}
		co v=get(1, 0, N-1, n+1);
		cout<<setprecision(15)<<v.X<<" "<<v.Y<<'\n';
	}
}