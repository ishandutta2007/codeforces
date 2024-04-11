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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

LL n;
vector<LP> v1;

int main(){
	LL i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
	}
	sort(v1.begin(),v1.end());
	a=v1[1].first-v1[0].first,b=-1;
	for(i=2,j=2;i<n;i++){
		if(v1[i].first!=v1[0].first+a*j){
			if(b==-1)b=v1[i].second;
			else b=-2;
		}else j++;
	}
	if(b==-1)b=v1[0].second;
	if(b==-2){
		a=v1[2].first-v1[1].first;
		for(i=2;i<n;i++){
			if(v1[i].first!=v1[1].first+a*(i-1))break;
		}
		if(i==n)b=v1[0].second;
	}
	if(b==-2){
		a=v1[2].first-v1[0].first;
		for(i=2;i<n;i++){
			if(v1[i].first!=v1[0].first+a*(i-1))break;
		}
		if(i==n)b=v1[1].second;
	}
	cout<<b+1<<endl;
}