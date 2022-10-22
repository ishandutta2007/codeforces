#include<cstdio>
#include<cstdlib>
const int MAXN=105;
int n,k;
bool a[MAXN];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(k%3){
			if(n%3) puts("Alice");
			else puts("Bob");
		}
		else{
			int x=n%(k+1);
			if(!x) puts("Bob");
			else if(x==k) puts("Alice");
			else if(x%3) puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
}