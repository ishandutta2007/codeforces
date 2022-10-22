#include<iostream>
#include<cmath>
typedef long long int LL;
using namespace std;
int main(){
	LL n,m;
	LL a,b,c,d;
	LL s=0;
	cin>>n>>m>>a>>b;
	for(;n>1;){
		if(m==1){
			s=(n-1)*a;
			break;
		}
		if(n%m!=0){
			c=n%m;
			n-=c,s+=a*c;
			continue;
		}
		n/=m;
		c=n*(m-1);
		s+=min(c*a,b);
	}
	if(n==0)s-=a;
	cout<<s<<endl;
	return 0;
}