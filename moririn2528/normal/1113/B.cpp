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

int t[50005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int p,q;
	cin>>n;
	a=105,b=0;
	for(i=0;i<n;i++){
		cin>>t[i];
		if(a>t[i])a=t[i];
		b+=t[i];
	}
	c=0;
	for(i=0;i<n;i++){
		for(j=1;j<=t[i];j++){
			if(t[i]%j!=0)continue;
			p=t[i]/j+a*j-t[i]-a;
			if(p<c)c=p;
		}
	}
	cout<<b+c<<endl;
}