#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=50005;
int n,a[MAXN][5];
bool Check(int x,int y){
	if(!x) return 0;
	if(!y) return 1;
	int c=0;
	for(int i=0; i<5; i++)
		if(a[x][i]>a[y][i]) c++;
	return c>=3;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			for(int j=0; j<5; j++){
				double x;
				scanf("%lf",&x);
				a[i][j]=x*10+0.5;
				a[i][j]=-x;
			}
		int w=0;
		for(int i=1; i<=n; i++)
			if(!Check(w,i)) w=Check(i,w)*i;
		if(!w) w=-1;
		else{
			for(int i=1; i<=n; i++)
				if(w!=i&&!Check(w,i)){
					w=-1;
					break;
				}
		}
		printf("%d\n",w);
	}
	return 0;
}