#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define P 1000000007
#define N 100005

int n,c[5],e=4;
char s[N];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n){
		if(s[i]=='A') c[1]++;
		if(s[i]=='C') c[2]++;
		if(s[i]=='G') c[3]++;
		if(s[i]=='T') c[4]++;
	}
	sort(c+1,c+1+4);
	if(c[3]==c[4]){
		e--;
		if(c[2]==c[3]){
			e--;
			if(c[1]==c[2]) e--;
		}
	}
 	int ans=1;
 	e=4-e+1;
 	rep(i,1,n) ans=(LL)ans*e%P;
 	printf("%d\n",ans);
}