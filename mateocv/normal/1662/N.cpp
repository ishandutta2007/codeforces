#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s, thxdem=e;i < thxdem;i++)
#define pb push_back
#define fst first
#define snd second
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()
#define mset(a,b) memset(a,b,sizeof(a))
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n;

int main(){
	FIN;
	cin>>n;
	vector<vll> a(n,vll(n)),sortRow(n,vll(n)),sortCol(n,vll(n));
	fore(i,0,n){fore(j,0,n){
		cin>>a[i][j];
		sortRow[i][j] = a[i][j];
		sortCol[j][i] = a[i][j];
	}}
	fore(i,0,n){
		sort(ALL(sortRow[i]));
		sort(ALL(sortCol[i]));
	}
	ll ans = 0;
	fore(i,0,n){fore(j,0,n){
		ll lessRow = lower_bound(ALL(sortRow[i]),a[i][j]) - sortRow[i].begin();
		ll lessCol = lower_bound(ALL(sortCol[j]),a[i][j]) - sortCol[j].begin();
		ans += lessRow*(n-1-lessCol) + lessCol*(n-1-lessRow);
	}}
	cout<<ans/2<<'\n';
	return 0;
}