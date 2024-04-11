#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100100;
int a[N];
int p[N]={0};
bool work(){
	int n,k;
	scanf("%d%d",&n,&k);
	bool w=false;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x>=k?1:0;
		if(x==k){
			w=true;
		}
		p[i]=p[i-1]+a[i];
	}
	if(!w){
		return false;
	}
	if(n==1){
		return true;
	}
	int mmn=1e5;
	int mn=0;
	for(int i=1;i<=n;i++){
		if((2*p[i]-i)-mmn-1>=0){
			return true;
		}
		mmn=mn;
		mn=min(mn,2*p[i]-i);
	}
	return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		puts(work()?"yes":"no");
	}
	return 0;
}