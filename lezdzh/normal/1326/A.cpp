#include<cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		if(n==1)printf("-1\n");
		else{
			for(int i=1;i<n;i++)
				printf("7");
			printf("4\n");
		}
	}
}