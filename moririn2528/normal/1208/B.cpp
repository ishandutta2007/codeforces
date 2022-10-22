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

map<int,int> m1;
bool used[2005];
int t[2005];

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(m1[a]==0)m1[a]=i+1;
		t[i]=m1[a];
	}
	a=0;
		for(j=n-1;j>=0;j--,a++){
			if(used[t[j]])break;
			used[t[j]]=true;
		}
		for(j++;j<n;j++){
			used[t[j]]=false;
		}
		b=a;
	for(i=0;i<n;i++){
		if(used[t[i]])break;
		used[t[i]]=true;
		a=i+1;
		for(j=n-1;j>=0;j--,a++){
			if(used[t[j]])break;
			used[t[j]]=true;
		}
		for(j++;j<n;j++){
			used[t[j]]=false;
		}
		if(b<a)b=a;
	}
	cout<<n-b<<endl;
}