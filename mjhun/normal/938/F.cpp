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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;


char r[5005];
char s[5005];
bool v[5005];
int c;int n;
int l=1,t=1;
vector<int> w,w2;

void dfs(int i){
	if(i>n)return;
	if(v[i])return;
	v[i]=true;w2.pb(i);
	int b=i-c;int q=t-b;
	fore(j,0,l)if((q>>j)&1)dfs(i+(1<<j));
}

int main(){
	scanf("%s",s);n=strlen(s);
	if(n==1){puts(s);return 0;}
	w.reserve(n+5);w2.reserve(n+5);
	while(2*t+1<n){
		t=2*t+1;
		l++;
	}
	assert(t==(1<<l)-1);
	fore(i,0,t+1)w.pb(i);
	fore(i,0,n){c=i+1;
		char mn='z';
		for(int j:w)mn=min(mn,s[j]);
		r[i]=mn;
		w2.resize(0);
		for(int j:w)if(s[j]==mn){
			dfs(j+1);
		}
		w.swap(w2);
		for(int j:w)v[j]=false;
	}
	puts(r);
	return 0;
}