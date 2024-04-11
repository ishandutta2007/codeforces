#include<iostream>
#include<algorithm>
#include<cstdio>
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
using namespace std;
int n,a[200002];
int main(){
	cin>>n;
	F(i,1,n)cin>>a[i];
	F(i,1,n)a[i]+=i;
	sort(a+1,a+n+1);
	F(i,1,n-1)if(a[i]==a[i+1]){
		puts(":(");
		return 0;
	}
	F(i,1,n)cout<<a[i]-i<<' ';
}