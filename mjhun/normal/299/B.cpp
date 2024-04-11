#include <iostream>
using namespace std;

char rd[300005];

int min(int a, int b){
	return (a<b)?a:b;
}

int main(){
	int n,k,i,j,m,l;
	bool b=true;
	cin>>n>>k;
	for(i=1;i<=n;++i)
		cin>>rd[i];
	
	i=1;
	while(b&&i<n){
		l=min(i+k,n);
		for(j=i;j<=l;++j){
			if(rd[j]=='.')
				m=j;
		}
		b = m!=i;
		i=m;
	}
	
	cout<<(b?"YES":"NO")<<endl;
	
	return 0;
}