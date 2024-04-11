#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int isp[3005];
vector<int> primes;

int isalm(int k){
	int r=0;
	for(vector<int>::iterator it=primes.begin();it!=primes.end()&&*it<=k&&r<=2;++it){
		r+=!(k%*it);
	}
	return r==2;
}

int main(){
	int i,j,n,r=0,k;
	for(i=2;i<=3000;++i)
		isp[i]=true;
	for(i=2;i<=3000;++i){
		if(isp[i]){
			primes.push_back(i);
			for(j=2*i;j<=3000;j+=i)
				isp[j]=false;
		}
	}
	cin>>n;
	for(i=1;i<=n;++i)
		r+=isalm(i);
	cout<<r<<endl;
	return 0;	
}