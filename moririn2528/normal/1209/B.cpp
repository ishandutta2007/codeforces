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

int t[105][2];
int li[105];
string sa;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	cin>>sa;
	for(i=0;i<n;i++){
		if(sa[i]=='1')li[i]=1;
	}
	for(i=0;i<n;i++){
		cin>>t[i][0]>>t[i][1];
	}
	int s=0;
	for(i=0;i<1000;i++){
		a=0;
		for(j=0;j<n;j++){
			if(i>=t[j][1] && i%t[j][0]==t[j][1]%t[j][0])li[j]=1-li[j];
			if(li[j])a++;
		}
		s=max(s,a);
	}
	cout<<s<<endl;
}