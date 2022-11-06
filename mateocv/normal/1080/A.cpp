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

int techo(int x,int y){
	if(x%y==0){return x/y;
	}
	return x/y+1;
}

int main(){
	
	double n, k; cin>>n>>k;
	cout<<techo(2*n,k)+techo(5*n,k)+techo(8*n,k);
	
	return 0;
}