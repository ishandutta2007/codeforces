#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int sum=accumulate(s+1,s+n+1,0)-'a'*n+n;
		if(n&1){
			int b=min(s[1],s[n])-'a'+1,a=sum-b;
			printf("%s %d\n",a>b?"Alice":"Bob",abs(a-b));
		}
		else printf("Alice %d\n",sum);
	}
	return 0;
}