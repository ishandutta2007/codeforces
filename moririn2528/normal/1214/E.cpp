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

int t[100005];
int pl[200005];
vector<pair<int,int> > v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		v1.push_back(make_pair(t[i],2*i+1));
	}
	sort(v1.rbegin(),v1.rend());
	pl[0]=v1[0].second;
	for(i=1;i<n;i++){
		pl[i]=v1[i].second;
		cout<<pl[i-1]<<" "<<pl[i]<<endl;
	}
	for(i=0;i<n;i++){
		a=v1[i].second+1,b=i+v1[i].first;
		if(pl[b]==0)pl[b]=a;
		cout<<pl[b-1]<<" "<<a<<endl;
	}
}