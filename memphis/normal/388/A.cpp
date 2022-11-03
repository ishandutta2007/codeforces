#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 105
#define rep(i,x,y) for(int i=x;i<=y;++i)

int N,x[maxn],ans;

int main(){
	scanf("%d",&N);
	rep(i,1,N) scanf("%d",&x[i]);
	sort(x+1,x+1+N);
	
	rep(i,1,N){
		if(x[i]>=0){
			int sum=0;
			++ans;
			rep(j,i,N){
				if(x[j]>=sum){
					++sum;
					x[j]=-1;
				}
			}
		}
	}
	printf("%d\n",ans);
}