#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d",&n);
	if(n<=4){
		if(n==1) n++;
		printf("%d\n",n-1);
		for(int i=1; i<n; i++)
			printf("%d %d\n",i,i);
	}else{
		int k=(n*2+1)/3,q=n*2-k*2-1,w;
		printf("%d\n",k);
		if(k&1){
			w=k+1>>1;
			for(int i=1; i<=w; i++)
				printf("%d %d\n",i,w-i+1);
			for(int i=w+1,j=k; i<=k; i++,j--)
				printf("%d %d\n",i,j);
		}else{
			w=k>>1;
			for(int i=1; i<=w; i++)
				printf("%d %d\n",i,w-i+1);
			for(int i=w+2,j=k; i<=k; i++,j--)
				printf("%d %d\n",i,j);
			printf("%d %d\n",w+1,w+1);
		}
	}
	return 0;
}