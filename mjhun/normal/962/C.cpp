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

int n;
vector<int> d;

int main(){
	scanf("%d",&n);int nn=n;
	while(nn)d.pb(nn%10),nn/=10;
	int r=-1;
	for(int i=1;i*i<=n;++i){
		int m=i*i,k=0,q=0;
		while(m&&k<SZ(d)){
			while(k<SZ(d)&&d[k]!=m%10)k++;
			if(k==SZ(d))break;
			k++;q++;
			m/=10;
		}
		if(!m)r=SZ(d)-q;
	}
	printf("%d\n",r);
	return 0;
}