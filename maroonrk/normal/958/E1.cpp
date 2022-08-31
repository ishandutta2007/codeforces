#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define show(x) cout<< #x<< " "<<(x)<<endl;
#define all(c) c.begin(),c.end()
#define chmax(x,y) x = max(x,y)
#define fs first
#define sc second
#define pb push_back

using namespace std;
using D = double;
using P = complex<D>;
using L = pair<P,P>;

D cro(P a,P b){
	return imag(conj(a)*b);
}
int ccw(P a,P b,P c){
	if(cro(b-a,c-a)>0) return 1;
	return -1;
}

bool iSS(L a,L b){
	return ccw(a.fs,a.sc,b.fs)*ccw(a.fs,a.sc,b.sc)<=0 && ccw(b.fs,b.sc,a.fs) * ccw(b.fs,b.sc,a.sc)<=0;
}

bool f[10][10][10][10];

int main(){
	int A,B;
	cin>>A>>B;
	if(A!=B){
		puts("No");
		return 0;
	}
	int N = A;
	vector<P> a,b;
	rep(i,N){
		int x,y;
		cin>>x>>y;
		a.pb(P(x,y));
	}
	rep(i,N){
		int x,y;
		cin>>x>>y;
		b.pb(P(x,y));
	}
	rep(i,N) rep(j,N) rep(k,N) rep(l,N){
		f[i][j][k][l] = iSS(L(a[i],b[j]),L(a[k],b[l]));
	}
	vector<int> o(N);
	rep(i,N) o[i] = i;
	do{
		vector<L> ls;
		bool ok = 1;
		rep(i,N) rep(j,i) if(f[i][o[i]][j][o[j]]) ok = 0;
		if(ok){
			puts("Yes");
			return 0;
		}
	}while(next_permutation(all(o)));
	puts("No");
}