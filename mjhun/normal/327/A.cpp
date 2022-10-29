#include <iostream>
using namespace std;
int a[105];

int main(){
	int n,i,j,k,s=0,m=0;
	bool ones=true;
	cin>>n;
	a[0]=0;
	for(i=1;i<=n;++i){
		cin>>k;
		ones=ones&&k;
		s+=k;
		m+= k?-1:1;
		a[i]=m;		
	}
	m=0;
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			k=a[j]-a[i-1];
			if(m<k)m=k;
		}
	}
	cout<<s+m-(int)ones<<endl;
	return 0;
}