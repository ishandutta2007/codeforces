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

int n;
char s[100005];

bool can(int k){
	int l=-1,r=-1;
	fore(i,0,n){
		if(s[i]=='P'){
			if(l>=0){
				if(i-l>k)return false;
				int a=k-(i-l);
				r=max(r,l+a);
				a=(k-(i-l))/2;
				r=max(r,i+a);
				l=-1;
			}
			else {
				r=max(r,i+k);
			}
		}
		else if(s[i]=='*'){
			if(i<=r)continue;
			if(l<0)l=i;
		}
	}
	return l<0;
}

int main(){
	scanf("%d%s",&n,s);
	int a=1,b=300005;
	while(b-a>1){
		int m=(a+b)/2;
		if(can(m-1))b=m;
		else a=m;
	}
	printf("%d\n",a);
	return 0;
}