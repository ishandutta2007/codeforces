#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		int a=0,b=0;
		for(int i=1;i<=2*n;i++){
			int x;
			scanf("%d",&x);
			if(x&1)a++;
			else b++;
		}
		printf(a==b?"Yes\n":"No\n");
	}
}