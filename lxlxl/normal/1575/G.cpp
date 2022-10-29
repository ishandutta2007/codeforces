#include <bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;
const ll M = 1000000007;
ll n;
ll phi[N+50],notp[N+50],p[N+50];
ll tag[N+50],b[N+50];
vector<ll> fac[N+50];
ll a[N+50];
void prepare(){
	phi[1]=1;
	notp[1]=1;
	for (int i=2;i<=N;i++){
		if (!notp[i]) p[++p[0]]=i,phi[i]=i-1;
		for (int j=1,x;j<=p[0] && (x=i*p[j])<=N;j++){
			notp[x]=1;
			if (i%p[j]){
				phi[x]=phi[i]*(p[j]-1);
			}
			else{
				phi[x]=phi[i]*p[j];
				break;
			}
		}
	}
	for (int i=1;i<=N;i++)
		for (int j=i;j<=N;j+=i) fac[j].push_back(i);
}
int main(){
	ios_base::sync_with_stdio(false);
	prepare();
/*	for (int i=1;i<=20;i++) cerr << i << " ";cerr << endl;
	for (int i=1;i<=20;i++) cerr << phi[i] << " ";cerr << endl;
	for (int i=1;i<=20;i++){
		for (auto y:fac[i]) cerr << y << " ";
		cerr << endl;
	}*/
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int d=1;d<=n;d++){
		for (int i=d;i<=n;i+=d){
			for (auto k:fac[a[i]]){
				b[k]=(b[k]+(2*tag[k]+1) % M*phi[d]) % M;
				tag[k]++;
			}
		}
		for (int i=d;i<=n;i+=d)
			for (auto k:fac[a[i]]) tag[k]=0;
	}
	ll ans=0;
	for (int i=1;i<=100000;i++) ans=(ans+b[i]*phi[i]) % M;
	cout << ans << '\n';
	return 0;
}