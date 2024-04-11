#include<cstdio>
#include<set>
using namespace std;
const int N=200002;
multiset<int>S;
int n,i,k,x,a[N],b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	S.insert(n);
	for(i=1;i<=n;i++)
		scanf("%d",b+i),S.insert(b[i]);
	for(i=1;i<=n;i++){
		k=(n-a[i])%n;
		if((x=*S.lower_bound(k))!=n){
			printf("%d ",(x+a[i])%n);
			S.erase(S.lower_bound(k));
		}
		else{
			x=*S.lower_bound(0);
			printf("%d ",(x+a[i])%n);
			S.erase(S.lower_bound(0));	
		}
	}
}