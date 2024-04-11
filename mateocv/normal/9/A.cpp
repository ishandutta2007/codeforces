#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int x,y; cin>>x>>y;
	int m=max(x,y);
	switch(m){
		case 1: cout<<"1/1"; break;
		case 2: cout<<"5/6"; break;
		case 3: cout<<"2/3"; break;
		case 4: cout<<"1/2"; break;
		case 5: cout<<"1/3"; break;
		case 6: cout<<"1/6"; break;
	}
	
	return 0;
}