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

int n,k;
int a[100005],s;
vector<int> r;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i),s+=a[i];
	if(s%k){puts("No");return 0;}
	s/=k;
	int ss=0;int t=1,q=0;
	fore(i,0,n){
		ss+=a[i];q++;
		if(ss>s*t){puts("No");return 0;}
		if(ss==s*t){r.pb(q);t++;q=0;}
	}
	puts("Yes");
	fore(i,0,k)printf("%d%c",r[i]," \n"[i==k-1]);
	return 0;
}