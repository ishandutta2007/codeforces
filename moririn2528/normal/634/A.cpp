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

int t1[200005];
int t2[200005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t1[i];
		if(i!=0 && t1[i-1]==0)t1[i-1]=t1[i],t1[i]=0;
	}
	for(i=0;i<n;i++){
		cin>>t2[i];
		if(t2[i]==t1[0])a=i;
	}
	b=0;
	for(i=0;i<n-1;i++){
		while(t1[i]!=t2[a]){
			a++,b++;
			if(a>=n)a-=n;
		}
		if(b>n)break;
	}
	if(b<n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}