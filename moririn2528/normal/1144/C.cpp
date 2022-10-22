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

int used[200005];
vector<int> v1,v2;

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	bool s=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(used[a]>=2){
			s=false;
			continue;
		}
		if(used[a]==1)v2.push_back(a);
		else v1.push_back(a);
		used[a]++;
	}
	if(!v1.empty())sort(v1.begin(),v1.end());
	if(!v2.empty())sort(v2.rbegin(),v2.rend());
	print_YES_NO(s);
	if(!s)return 0;
	cout<<v1.size()<<endl;
	for(i=0;i<v1.size();i++){
		printf("%d%c",v1[i],(i!=v1.size()-1?' ':'\n'));
	}
	cout<<v2.size()<<endl;
	for(i=0;i<v2.size();i++){
		printf("%d%c",v2[i],(i!=v2.size()-1?' ':'\n'));
	}
	if(v2.size()==0)cout<<endl;
}