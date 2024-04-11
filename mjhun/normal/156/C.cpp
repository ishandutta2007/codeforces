#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int f[128][4096];
char s[128];
int n,r;

int main(){
	f[0][0]=1;
	fore(l,1,101){
		fore(s,0,2605){
			fore(k,0,min(25,s)+1)f[l][s]+=f[l-1][s-k],f[l][s]%=MOD;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);n=strlen(s);
		r=0;
		fore(i,0,n)r+=s[i]-'a';
		printf("%d\n",(f[n][r]+MOD-1)%MOD);
	}
	return 0;
}