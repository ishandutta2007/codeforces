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

LL t[2];
LL s[2];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	t[1]=1;
	for(i=0;i<n;i++){
		cin>>a;
		if(a<0)swap(t[0],t[1]);
		s[0]+=t[0],s[1]+=t[1];
		t[1]++;
	}
	cout<<s[0]<<" "<<s[1]<<endl;
}