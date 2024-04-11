#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

set<int> primes;
int sumr[500];
int sumc[500];

void addpr(int n){
	bool b;
	int i,j;
	primes.insert(2);
	for(i=3;i<=n;i+=2){
		b=true;
		j=3;
		while(b&&j*j<=i){
			b=i%j!=0;
			j+=2;
		}
		if(b)
			primes.insert(i);
	}
}

int main(){
	int n,m,i,j,k,p;
	cin>>n>>m;
	for(i=0;i<n;++i) sumr[i]=0;
	for(j=0;j<m;++j) sumc[j]=0;
	addpr(100100);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			cin>>k;
			p=*primes.lower_bound(k)-k;
			sumr[i]+= p;
			sumc[j]+= p;
		}
	}
	p=sumr[0];
	for(i=1;i<n;++i){
		if(sumr[i]<p) p=sumr[i];
	}
	for(j=0;j<m;++j){
		if(sumc[j]<p) p=sumc[j];
	}
	cout<<p<<endl;
	return 0;
}