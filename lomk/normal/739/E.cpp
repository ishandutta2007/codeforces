#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define int long long
#define bit(x,y) ((x>>y)&1)
#define sp ' '
#define endl '\n'
template<typename X, typename Y>
ostream &operator<<(ostream &os, pair<X,Y> &inp){
	os << inp.X << sp << inp.Y;
	return os;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &X){
	for (auto it:X) os << it << sp;
		return os;
}
#ifdef UncleGrandpa
void print(){cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values){cout << value << ' ',print(values...);}
#endif
const int N = 2005;
int n,a,b;
double ax[N],bx[N];
pair<double,int> f[N][N];

pair<double,int> cal(double pen){

	auto Max = [&](pair<double,int> &A, const pair<double,int> &B){
		if (A.fi<B.fi) A = B;
		else if (A.fi==B.fi&&A.se>B.se) A = B;
		return;
	};
	memset(f,-60,sizeof(f));
	f[0][0] = {0,0};
	loop(i,0,n-1){
		loop(j,0,a){
			if (f[i][j].fi<0) continue;
			// no throw
			Max(f[i+1][j],f[i][j]);
			// throw a
			if (j+1<=a)
				Max(f[i+1][j+1],{f[i][j].fi+ax[i+1],f[i][j].se});
			// throw b
			Max(f[i+1][j],{f[i][j].fi+bx[i+1]-pen,f[i][j].se+1});
			// throw both
			if (j+1<=a){
				double both_prob = ax[i+1]+bx[i+1]-ax[i+1]*bx[i+1];
				Max(f[i+1][j+1],{f[i][j].fi+both_prob-pen,f[i][j].se+1});
			}
		}
	}
	return f[n][a];
}

signed main(){
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif
	cin >> n >> a >> b;
	loop(i,1,n) cin >> ax[i];
	loop(i,1,n) cin >> bx[i];
	double l = 0,r=1e9;
	loop(i,1,100){
		double mid = (l+r)/2;
		auto [ans,b_used] = cal(mid);
		// print(mid,ans,b_used);
		if (b_used>b) l = mid;
		else r = mid;
	}
	auto [ans,b_used] = cal(r);
	cout << setprecision(6) << fixed << ans+b*l << endl; // restore answer
}