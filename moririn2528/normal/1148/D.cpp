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

vector<P> v[2];

int main(){
	int n;
	int a,b,c;
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		if(a>b)v[0].push_back(make_pair(a,i+1));
		else v[1].push_back(make_pair(b,i+1));
	}
	sort(v[0].begin(),v[0].end());
	sort(v[1].rbegin(),v[1].rend());
	if(v[0].size()>v[1].size())a=0;
	else a=1;
	cout<<v[a].size()<<endl;
	for(int i=0;i<v[a].size();i++)printf("%d%c",v[a][i].second,(i!=v[a].size()-1?' ':'\n'));

}