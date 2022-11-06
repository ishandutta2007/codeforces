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
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main() {FIN;
int k,n; cin>>n>>k;
int suma=0,sumat=0,pag[n];
fore(i,0,n){cin>>pag[i];
}
int maxx=0;
fore(i,0,n){
sumat+=pag[i];}
suma=sumat;
fore(j,0,k){
for(int i=j;i<n;i+=k){
suma-=pag[i];
}
if(abs(suma)>maxx){maxx=abs(suma);
}
suma=sumat;
}
cout<<maxx;
return 0;
}