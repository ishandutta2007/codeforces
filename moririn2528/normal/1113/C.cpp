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

LL t[300005];
LL num[4000005];

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		t[i+1]=t[i]^a;
	}
	a=0;
	for(i=0;i<2;i++){
		memset(num,0,sizeof(num));
		for(j=0;j<=n;j++){
			if((i+j)%2==0)continue;
			a+=num[t[j]];
			num[t[j]]++;
		}
	}
	//array_show(t,n+1);
	cout<<a<<endl;
}