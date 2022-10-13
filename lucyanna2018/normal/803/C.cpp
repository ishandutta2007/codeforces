#include<bits/stdc++.h>
using namespace std;
#define int64 long long int
bool chk(int64 n,int64 k){
	for(int64 i=1; i<=k; i++){
		n-=i;
		if(n<0)
			return true;
	}
	return false;
}
int64 r,n,k;
void tst(int64 x){
	if(x >= (1+k)*k/2)
		r = min(r, x);
}
int main(){
	cin>>n>>k;
	if(chk(n,k)){
		cout<<"-1"<<endl;
		return 0;
	}
	r=n;
	for(int64 i=2; i*i<=n; i++)
		if(n%i==0){
			tst(i);
			tst(n/i);
		}
	int64 w = n/r;
	for(int64 i=1; i<k; i++){
		printf("%I64d ",i*w);
		n -= i*w;
	}
	printf("%I64d\n",n);
	return 0;
}