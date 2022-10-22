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

string sa;
int num[2];
int t[2];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	cin>>sa;
	for(i=0;i<n;i++){
		j=i/(n/2);
		if(sa[i]=='?')num[j]++;
		else t[j]+=(int)sa[i]-(int)'0';
	}
	t[0]+=(num[0]-num[1])/2*9;
	if(t[0]!=t[1])cout<<"Monocarp"<<endl;
	else cout<<"Bicarp"<<endl;
}