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

int x[200005],r;

int main(){
	int n,s;
	scanf("%d%d",&n,&s);s--;
	fore(i,0,n){
		scanf("%d",x+i);
		if(i==s&&x[i])x[i]=0,r++;
	}
	sort(x,x+n);
	int k=0,i=1,j=n;
	while(i<j){
		if(!x[i])r++,k++,i++;
		else if(x[i]>x[i-1]+1){
			if(k)k--;
			else r++,j--;
			x[i-1]++;
		}
		else i++;
	}
	printf("%d\n",r);
	return 0;
}