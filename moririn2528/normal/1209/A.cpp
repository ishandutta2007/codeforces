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

vector<int> v1;
bool used[105];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		if(used[i])continue;
		s++;
		for(j=i;j<n;j++){
			if(v1[j]%v1[i]==0)used[j]=true;
		}
	}
	cout<<s<<endl;
}