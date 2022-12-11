#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(a==1){
			printf((n%b==1||b==1)?"Yes\n":"No\n");
			continue;
		}
		for(long long o=1;o<=n;o*=a){
			if((n-o)%b==0){printf("Yes\n");goto ed;}
		}
		printf("No\n");
		continue;
ed:;
	}
}