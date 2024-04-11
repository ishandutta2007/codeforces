#include <bits/stdc++.h>
#define lim 5
using namespace std;
typedef long long ll;
const ll M=1000000007;
const ll inv2=(M+1)>>1;
int n,Q;
ll a[200050];
ll sum[lim+10][200050];
ll coff[lim+50][lim+50];
ll sumnk[lim+50];
ll fac[200050],ifac[200050];

map<ll,int> dict;
set<ll> pos[200050];
int id;
inline ll ksm(ll a,ll x){
	ll ret=1;
	for (;x;x>>=1,a=a*a % M) if (x&1) ret=ret*a % M;
	return ret;
}
inline ll inv(ll a){return ksm(a,M-2);}
void prepare(){
	fac[0]=1;
	for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i % M;
	ifac[200000]=inv(fac[200000]);
	for (int i=200000-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1) % M;
}
ll C(ll n,ll m){
	if (m<0 || m>n) return 0;
	return fac[n]*ifac[m] % M*ifac[n-m] % M;
}
bool fd(int L,int R,ll v){
	if (dict.find(v)==dict.end()) return 0;
	int vid=dict[v];
	ll tmp=*(pos[vid].lower_bound(L));
	if (tmp<=R) return 1;
	return 0;
}
ll checksum(ll a,ll d,ll k){
	ll sum=0;
//	cerr << "checksum" << "\n";
//	cerr << a << " " << d << " " << k << endl;
	for (int i=0;i<=k;i++){
		sum=(sum+ksm(a,k-i)*ksm(d,i) % M*sumnk[i] % M*C(k,i)) % M;
//		cerr << i << " " << sum << endl;
	}
	return sum;
}
namespace GE{
	ll a[lim+5][lim+5];
	void init(){
		memset(a,0,sizeof(a));
	}
	void gauss(int ROW,int COLUMN){
		int m=COLUMN,r=1;
		int n=ROW;
		for (int i=1;i<=m && r<=n;i++){
			ll maxx=0;
			int maxp=r;
			for (int j=r;j<=n;j++){
				if (a[j][i]!=0){
					maxx=a[j][i],maxp=j;
					break;
				}
			}
			if (maxx==0) continue;
			for (int j=i;j<=m;j++) swap(a[r][j],a[maxp][j]);
			for (int j=r+1;j<=m;j++){
				ll t=a[j][i]*inv(a[r][i]) % M;
				for (int k=i;k<=m;k++){
					a[j][k]=(a[j][k]+M-t*a[r][k]%M) % M;
				}
			}
			r++;
		}
		for (int i=n;i>=1;i--){
			for (int j=1;j<=m;j++){
				if (a[i][j]!=0){
					ll t=a[i][j];
					ll invt=inv(t);
					for (int l=j;l<=m;l++) a[i][l]=a[i][l]*invt % M;
					for (int k=i-1;k>=1;k--){
						ll t=a[k][j]*inv(a[i][j]) % M;
						for (int l=j;l<=m;l++)
							a[k][l]=(a[k][l]+M-t*a[i][l] % M) % M;
					}
					break;
				}
			}
		}
	}
}
void getcoff(){
	for (int now=0;now<=lim;now++){
	//	cerr << now << "\n";
		GE::init();
		ll nowsum=ksm(0,now);
		for (int i=1;i<=now+2;i++){
			for (int j=1;j<=now+2;j++) GE::a[i][j]=ksm(i,j-1);
			nowsum=(nowsum+ksm(i,now)) % M;
			GE::a[i][now+3]=nowsum;
		}
	//	for (int i=1;i<=now+2;i++){
	//		for (int j=1;j<=now+3;j++) cerr << GE::a[i][j] << " ";
	//		cerr << "\n";
	//	}
	//	cerr << "\n";
		GE::gauss(now+2,now+3);
		for (int i=1;i<=now+2;i++) coff[now][i-1]=GE::a[i][now+3];
		
	//	for (int i=0;i<=now+1;i++) cerr << coff[now][i] << " ";
	//	cerr << "\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	prepare();
	cin >> n >> Q;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (dict.find(a[i])==dict.end()) dict[a[i]]=++id;
		pos[dict[a[i]]].insert(i);
	}
/*	for (int i=0;i<=20;i++){
		cerr << i << " ";
		if (dict.find(i)!=dict.end()) cerr << dict[i];
		cerr << "\n";
	}
	cerr << "\n";
	for (int i=1;i<=id;i++){
		for (auto y:pos[i]) cerr << y << " ";
		cerr << "\n";
	}
	cerr << "\n";*/
	for (int j=1;j<=lim;j++){
		for (int i=1;i<=n;i++) sum[j][i]=(sum[j][i-1]+ksm(a[i],j)) % M;
	}
/*	for (int j=1;j<=lim;j++){
		for (int i=1;i<=n;i++) cerr << sum[j][i] << " ";
		cerr << "\n";
	}*/
	getcoff();
	for (;Q--;){
		ll L,R,D;
		cin >> L >> R >> D;
		int len=R-L+1;
		ll tmp=(sum[1][R]-sum[1][L-1]+M)*2 % M*inv(len) % M;
		ll st=(tmp-(len-1)*D % M+M)*inv2 % M;
		if (!fd(L,R,st) || !fd(L,R,(st+(len-1)*D) % M)) cout << "No\n";
		else{
			bool flag=1;
			for (int i=0;i<=lim;i++) sumnk[i]=0;
			for (int i=0;i<=lim;i++)
				for (int j=0;j<=i+1;j++) sumnk[i]=(sumnk[i]+coff[i][j]*ksm(len-1,j)) % M;
		//	for (int i=0;i<=lim;i++) cerr << sumnk[i] << " ";
		//	cerr << "\n";
			for (int i=1;i<=lim;i++) if (checksum(st,D,i)!=(sum[i][R]-sum[i][L-1]+M) % M){
				flag=0;
				break;
			}
		//	for (int i=1;i<=lim;i++) cerr << checksum(st,D,i) << "\n";
			if (!flag) cout << "No\n";
			else cout << "Yes\n";
		}
	}
	return 0;
}