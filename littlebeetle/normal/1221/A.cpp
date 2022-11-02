#include<cstdio>
#include<cstring>
using namespace std;
const int N=2049;
int T,n,i,a,s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		while(n--){
			scanf("%d",&a);
			if(a<N)
			s[a]++;
		}
		for(i=1;i<2048;i*=2){
			while(s[i]>1){
				s[i*2]++;
				s[i]-=2;
			}
		}
		printf("%s\n",s[2048]?"YES":"NO");
	}
}