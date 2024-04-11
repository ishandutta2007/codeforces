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

char s[1<<20];int n;
int f[1<<20][2];
int c[1<<20][2];

int main(){
	scanf("%s",s+1);s[0]='0';n=strlen(s);
	fore(i,0,n)s[i]-='0';
	f[0][0]=0;f[0][1]=1;
	c[0][0]=0;c[0][1]=1;
	fore(i,1,n)fore(k,0,2){
		f[i][k]=1<<30;
		// nada
		if(k==s[i]){
			if(f[i-1][k]<f[i][k])f[i][k]=f[i-1][k],c[i][k]=0;
		}
		// +1
		if(k!=s[i]){
			if(1+f[i-1][0]<f[i][k])f[i][k]=1+f[i-1][0],c[i][k]=1;
		}
		// -1
		if(k!=s[i]){
			if(1+f[i-1][1]<f[i][k])f[i][k]=1+f[i-1][1],c[i][k]=2;
		}
	}
	printf("%d\n",f[n-1][0]);
	int i=n-1,k=0;
	while(i>=0){
		if(c[i][k]==1)printf("+2^%d\n",n-1-i),k=0;
		else if(c[i][k]==2)printf("-2^%d\n",n-1-i),k=1;
		i--;
	}
	return 0;
}