#include<cstdio>
#include<iostream>
using namespace std;
int q;
long long x,y,k,a,b;
int main(){
	scanf("%d",&q);
	while(q--){
		cin>>x>>y>>k;
		a=x>y?x:y;
		if(a>k){
			printf("-1\n");
			continue;
		}
		if((x+y)%2){
			b=k-1;
		}
		else{
			if(a%2!=k%2)
				b=k-2;
			else
				b=k;
				
		}
		cout<<b<<endl;
	}
}