#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d;
	int p,q;
	cin>>a>>b>>c>>d>>n;
	p=a*(c-1)+b*(d-1);
	if(n>p)cout<<n-p<<" ";
	else cout<<0<<" ";
	if(c<d){
		if(a*c<n){
			q=a+(n-a*c)/d;
		}else q=n/c;
	}else{
		if(b*d<n){
			q=b+(n-b*d)/c;
		}else q=n/d;
	}
	cout<<q<<endl;
}