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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

char s[5005];int n,r;
bool w[5005][5005];

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n){
		int d=0,q=0;
		fore(j,i,n){
			if(s[j]=='?')q++;
			else if(s[j]=='(')d++;
			else {
				d--;
				if(d<0)d++,q--;
				if(q<0)break;
			}
			if((j-i)%2&&d<=q)w[i][j]=true;
			//r+=(j-i)%2&&d<=q;
		}
	}
	for(int i=n-1;i>=0;--i){
		int d=0,q=0;
		for(int j=i;j>=0;--j){
			if(s[j]=='?')q++;
			else if(s[j]==')')d++;
			else {
				d--;
				if(d<0)d++,q--;
				if(q<0)break;
			}
			if(d<=q&&w[j][i])r++;
		}
	}
	printf("%d\n",r);
	return 0;
}