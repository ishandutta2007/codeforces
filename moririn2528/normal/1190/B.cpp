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

vector<int> v1;

int main(){
	int n;
	LL a,b,c;
	LL s=0;
	int i,j,k;
	bool flag=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		s+=a;
	}
	sort(v1.begin(),v1.end());
	a=0;
	for(i=0;i<n-1;i++){
		if(v1[i]==v1[i+1]){
			a++;
			if(v1[i]==0 || (i!=0 && v1[i-1]==v1[i]-1))flag=false;
		}
	}
	if(a>=2)flag=false;
	if(!flag){
		cout<<"cslnb"<<endl;
		return 0;
	}
	s-=n*(n-1)/2;
	if(s%2==0)cout<<"cslnb"<<endl;
	else cout<<"sjfnb"<<endl;
}