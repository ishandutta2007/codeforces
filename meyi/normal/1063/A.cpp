#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int n;
char s[maxn];
int main(){
	scanf("%d%s",&n,s+1);
	sort(s+1,s+n+1);
	puts(s+1);
	return 0;
}