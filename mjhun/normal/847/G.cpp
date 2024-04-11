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

const int MXN=1e3+1;
int N;
bool A[MXN][7];

int main(){
	cin >> N;
	fore(x,0,N) fore(y,0,7){
		char c; cin >> c;
		A[x][y]=c=='1';
	}
	int ans=0;
	fore(y,0,7){
		int cnt=0;
		fore(x,0,N)cnt+=A[x][y];
		ans=max(ans,cnt);
	}
	cout << ans << "\n";
	return 0;
}