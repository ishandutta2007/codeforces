#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

int ask(int x, int y){
	cout << "? "<<x << " " << y << endl;
	char c; cin>>c;
	return c=='>'?x:y;
}

vector<int> gmx(vector<int> v){
	if(SZ(v)==1) return v;
	vector<int> now;
	for(int i=0;i+1<SZ(v);i+=2){
		now.pb(ask(v[i],v[i+1]));
	}
	if(SZ(v)%2) now.pb(v.back());
	return gmx(now);
}

int ask2(int x, int y){
	cout << "? "<< x << " " << y << endl;
	char c; cin>>c;
	return c=='>'?y:x;
}

vector<int> gmn(vector<int> v){
	if(SZ(v)==1) return v;
	vector<int> now;
	for(int i=0;i+1<SZ(v);i+=2){
		now.pb(ask2(v[i],v[i+1]));
	}
	if(SZ(v)%2) now.pb(v.back());
	return gmn(now);
}

int main() {FIN;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n), up,dw;
		fore(i,0,n) a[i]=i+1;
		for(int i=0;i+1<n;i+=2){
			cout << "? " << a[i] << " " << a[i+1] << endl;
			char c; cin>>c;
			if(c=='>') up.pb(a[i]), dw.pb(a[i+1]);
			else up.pb(a[i+1]), dw.pb(a[i]);
		}
		if(n&1) up.pb(n), dw.pb(n);
		auto amx=gmx(up), amn=gmn(dw);
		cout << "! "<<amn[0] << " " << amx[0] << endl;
	}
}