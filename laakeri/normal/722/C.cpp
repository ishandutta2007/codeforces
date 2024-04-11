#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll ma=0;
int u[101010];
ll us[101010];

int getu(int x){
	if (u[x]==x) return x;
	return u[x]=getu(u[x]);
}
void un(int a, int b){
	a=getu(a);
	b=getu(b);
	us[a]+=us[b];
	u[b]=a;
	ma=max(ma, us[a]);
}

ll v[101010];

ll a[101010];
int d[101010];
int is[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		u[i]=i;
		us[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>d[i];
	}
	for (int i=n;i>=1;i--){
		ma=max(ma, a[d[i]]);
		if (is[d[i]-1]) un(d[i], d[i]-1);
		if (is[d[i]+1]) un(d[i], d[i]+1);
		is[d[i]]=1;
		v[i]=ma;
	}
	for (int i=2;i<=n+1;i++){
		cout<<v[i]<<'\n';
	}
}