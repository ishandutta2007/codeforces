#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#include<vector>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int P=1000000007;
const int N=200005;

int n,a[N];

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i),a[i]+=i;
	sort(a+1,a+1+n);
	rep(i,2,n) if(a[i]==a[i-1]){
		puts(":(");
		return 0;
	}
	rep(i,1,n) printf("%d ",a[i]-i);
}