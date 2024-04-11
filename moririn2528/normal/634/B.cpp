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
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n>>m;
	a=n-m;
	if(a%2==1){
		cout<<0<<endl;
		return 0;
	}
	a>>=1;
	if(a&m){
		cout<<0<<endl;
		return 0;
	}
	s=1;
	for(i=0;i<40;i++){
		b=(LL)1<<i;
		if(m&b)s*=2;
	}
	if(a==0)s-=2;
	cout<<s<<endl;
}