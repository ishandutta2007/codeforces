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
char s[1<<19];
bool v[1<<19];
vector<int> w[32];

int main(){
	mset(v,true);
	scanf("%d%d%s",&n,&k,s);
	fore(i,0,n)w[s[i]-'a'].pb(i);
	fore(j,0,26){
		for(int i:w[j]){
			v[i]=false;
			k--;
			if(!k)break;
		}
		if(!k)break;
	}
	fore(i,0,n)if(v[i])putchar(s[i]);
	puts("");
	return 0;
}