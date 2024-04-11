#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
char s[1234],t[1234];int n,ans=0;
void dfs(int d,int w=1) {
	if(!t[d]) {
		if(t[0]=='0'&&n!=1) return;
		int g=0;
		for(int c=0;t[c];++c)
			g=g*10+t[c]-48,g%=25;
		if(!g) ans+=w;
		return;
	}
	if(t[d]!='_') dfs(d+1,w);
	else if(d>=1&&d<=n-3) dfs(d+1,w*10);
	else {
		for(t[d]='0'+(d==0&&n!=1);t[d]<='9';++t[d]) dfs(d+1,w);
		t[d]='_';
	}
}
int main()
{
	cin>>s;n=strlen(s); int a=0;
	for(int i=0;i<n;++i) a|=s[i]=='X';
	for(int x=0;x<=9&&(x==0||a);++x) {
		for(int j=0;j<n;++j) t[j]=(s[j]=='X')?(x+'0'):s[j];
		dfs(0);
	}
	cout<<ans<<"\n";
}