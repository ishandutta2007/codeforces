#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll m,n; cin>>m>>n;
	string s[m];
	fore(i,0,m){
	//	cout<<"HOLAAAA"<<endl;
		ll k; cin>>k;
		ll a[k];
		fore(j,0,k)cin>>a[j];
		sort(a,a+k);
		fore(j,0,n)s[i]+='0';
		fore(j,0,k)s[i][a[j]-1]='1';
	}
	ll tot=0;
	fore(i,0,m){
		fore(j,i+1,m){
			fore(ii,0,n){
				if(s[i][ii]==s[j][ii]&&s[i][ii]=='1'){
					tot++; break;
				}
			}
		}
	}
	if(tot==m*(m-1)/2){
		cout<<"possible";
	}else{
		cout<<"impossible";
	}
	return 0;
}