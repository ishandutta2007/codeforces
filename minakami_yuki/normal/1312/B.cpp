#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000;
int n,m;
int a[N];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=n;i>=1;--i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=n;i>=1;--i) printf("%d ",a[i]);
		cout<<endl;
	}
	return 0;
}