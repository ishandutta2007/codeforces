#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
#define PI 3.14159265
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main() {FIN;
 int n,R; cin>>n>>R;
 double res=R/(1/sin(PI/n)-1);
 cout<<fixed<<setprecision(15)<<res;
 //cout<<res;
 
 
}