#include<bits/stdc++.h>
using namespace std;
int n,k,nn,a[10005],f[10005];
long long sum=0,cur=0;
int ask(int x,int y){
	int ret=0,xx;
	printf("and %d %d\n",x,y);
	fflush(stdout);cin>>xx;ret+=xx;
	printf("or %d %d\n",x,y);
	fflush(stdout);cin>>xx;ret+=xx;
	return ret;
}
int main(){
	cin>>n>>k;
	if(n%2==0)nn=n-1;
	else nn=n;
	for(int i=1;i<=nn;i++){
		f[i]=ask(i,i%nn+1);
		sum+=f[i];
	}
	sum/=2;
	for(int i=1;i<=nn;i+=2){
		cur+=f[i];
	}
	a[1]=cur-sum;
	for(int i=2;i<=nn;i++){
		a[i]=f[i-1]-a[i-1];
	}
	if(nn<n){
		int sum=ask(nn,n);
		a[n]=sum-a[nn];
	}
	sort(a+1,a+n+1);
	cout<<"finish "<<a[k]<<endl;
	return 0;
}