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

vector<int> kmppre(vector<int>& t){
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
int kmp(vector<int>& s, vector<int>& t){
	int j=0,r=0;vector<int> b=kmppre(t);
	fore(i,0,s.size()){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())r++,j=b[j];
	}
	return r;
}

int n,m;
vector<int> s,t;

int main(){
	scanf("%d%d",&n,&m);
	int l;
	scanf("%d",&l);
	fore(i,1,n){
		int x;
		scanf("%d",&x);
		s.pb(x-l);l=x;
	}
	scanf("%d",&l);
	fore(i,1,m){
		int x;
		scanf("%d",&x);
		t.pb(x-l);l=x;
	}
	if(m>n)puts("0");
	else if(m==1)printf("%d\n",n);
	else printf("%d\n",kmp(s,t));
	return 0;
}