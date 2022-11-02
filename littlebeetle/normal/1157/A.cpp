#include<cstdio>
#include<map>
using namespace std;
map<int,bool>S;
int n,cnt;
int main(){
	scanf("%d",&n);
	while(!S[n]){
		cnt++;
		S[n]=1;
		n++;
		while(n%10==0)
			n/=10;
	}
	printf("%d",cnt);
}