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

int n;
bool v[8][8];

int main(){
	scanf("%d",&n);
	printf("a1");
	v[0][0]=1;
	int i=0,j=0,d=0;
	while(n){
		if(n==3&&i==6&&j==0){i++;}
		else if(n==2){
			if(i!=7&&j!=7)i=7;
			else if(i<6)i++;
			else {
				assert(abs(i-7)+abs(j-7)!=1);
				j=0;
				while(v[i][j])j++;
			}
		}
		else if(n==1){
			assert(i==7||j==7);
			i=7;j=7;
		}
		else {
			int q=0;
			fore(k,0,8)q+=v[i][k];
			if(q==8)i++;
			else if(i==0||i==2||i==4||i==7){
				j=0;
				while(v[i][j])j++;
			}
			else {
				j=7;
				while(v[i][j])j--;
			}
		}
		v[i][j]=true;
		printf(" %c%d",(char)('a'+i),j+1);
		n--;
	}
	puts("");
	return 0;
}