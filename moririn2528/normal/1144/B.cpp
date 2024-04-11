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

vector<int> v1,v2;

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(a%2==0)v1.push_back(a);
		else v2.push_back(a);
	}
	a=v1.size()-v2.size();
	if(abs(a)<=1){
		
		cout<<0<<endl;
		return 0;
	}
	if(a<0)v1.swap(v2),a=-a;
	sort(v1.begin(),v1.end());
	for(i=0;i<a-1;i++){
		s+=v1[i];
	}
	cout<<s<<endl;
	return 0;
}