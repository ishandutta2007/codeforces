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

#define MOD 1000000007

set<int> a,b,c;
int n,r=1;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		char s[16];int x;
		scanf("%s%d",s,&x);
		if(s[1]=='D'){
			if(!a.empty()&&x<*a.rbegin())a.insert(x);
			else if(!b.empty()&&x>*b.begin())b.insert(x);
			else c.insert(x);
		}
		else {
			if(c.count(x)){
				r+=r;
				if(r>=MOD)r-=MOD;
				for(int t:c){
					if(t<x)a.insert(t);
					else if(t>x)b.insert(t);
				}
				c.clear();
			}
			else if(a.count(x)){
				if(x!=*a.rbegin()){puts("0");return 0;}
				a.erase(x);
				for(int t:c)b.insert(t);
				c.clear();
			}
			else {
				assert(b.count(x));
				if(x!=*b.begin()){puts("0");return 0;}
				b.erase(x);
				for(int t:c)a.insert(t);
				c.clear();
			}
		}
	}
	r=(1LL*r*(SZ(c)+1))%MOD;
	printf("%d\n",r);
	return 0;
}