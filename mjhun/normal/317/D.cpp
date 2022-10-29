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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> asd={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
#define K 33000
bool w[K];

int main(){
	int n;
	scanf("%d",&n);
	int m=n,r=0;
	for(int i=2;i*i<=n;++i)if(!w[i]){
		int k=0;
		for(ll j=i;j<=n;j*=i){
			if(j<K)w[j]=true;
			m--;k++;
		}
		r^=asd[k];
	}
	r^=m&1;
	puts(r?"Vasya":"Petya");
	return 0;
}