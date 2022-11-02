#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	else{
		return (x*pot(x, p-1))%mod;
	}
}

ll inv(ll x){
	return pot(x, mod-2);
}

const int C=400000;
ll ke[404040];
ll kei[404040];

ll bin(int n, int k){
	return (((ke[n]*kei[k])%mod)*kei[n-k])%mod;
}

ll get(int n, int k){
	if (n==0) return 1;
	if (n%4==0){
		if (k<n/2){
			if (k%2==0) return bin(n/2-1, k/2);
			else return mod-bin(n/2-1, k/2);
		}
		else{
			return mod-get(n, n-k-1);
		}
	}
	else if(n%4==1){
		if (k%2==1) return 0;
		return bin(n/2, k/2);
	}
	else if(n%4==2){
		return bin(n/2-1, k/2);
	}
	else{
		assert(0);
	}
}

int go(vector<int> a){
	int n=a.size();
	vector<int> b(n);
	int t=0;
	for (int s=n;s>1;s--){
		for (int i=1;i<s;i++){
			if (t%2==0){
				b[i-1]=a[i-1]+a[i];
			}
			else{
				b[i-1]=a[i-1]-a[i];
			}
			t++;
		}
		for (int i=0;i<s;i++){
			a[i]=b[i];
		}
	}
	return a[0];
}

void pr(int n){
	for (int i=0;i<n;i++){
		vector<int> a(n);
		a[i]=1;
		cout<<go(a)<<" ";
	}
	cout<<endl;
}

ll a[202020];

ll b[5][5];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ke[0]=1;
	kei[0]=1;
	for (int i=1;i<=C;i++){
		ke[i]=ke[i-1]*(ll)i;
		ke[i]%=mod;
		kei[i]=inv(ke[i]);
	}
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int u=n;
	if (n%4==3){
		u=n-2;
	}
	int ss=1+n-u;
	for (int j=0;j<ss;j++){
		for (int i=0;i<n;i++){
			int c=i-j;
			if (c<0||c>=u) continue;
			b[0][j]+=a[i]*get(u, c);
			b[0][j]%=mod;
		}
	}
	ll ops=0;
	for (int i=0;i<u-1;i++){
		ops+=(ll)(n-i-1);
	}
	for (int i=u;i<n;i++){
		int s=n-i+1;
		for (int j=1;j<s;j++){
			if (ops%2) b[i-u+1][j-1]=(b[i-u][j-1]-b[i-u][j]+mod)%mod;
			else b[i-u+1][j-1]=(b[i-u][j-1]+b[i-u][j])%mod;
			ops++;
		}
	}
	cout<<b[n-u][0]<<endl;
}