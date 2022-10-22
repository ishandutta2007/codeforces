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

char ca[200005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	bool flag=true;
	cin>>n;
	cin>>ca;
	a=0;
	for(i=0;i<n;i++){
		if(ca[i]=='(')a++;
		else a--;
		if(a<-1)flag=false;
	}
	if(a!=0)flag=false;
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}