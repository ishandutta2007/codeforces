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
int t[200005];

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	bool pre=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t[i];
		used[t[i]]++;
	}
	for(i=0,a=0;i<200005;i++){
		if(used[a]<used[i])a=i;
	}
	cout<<n-used[a]<<endl;
	for(i=0;i<n;i++){
		if(t[i]==a && pre){
			pre=false;
			for(j=i-1;j>=0;j--){
				cout<<(t[j]<a?1:2)<<" "<<j+1<<" "<<j+2<<endl;
			}
		}
		if(t[i]==a || pre)continue;
		cout<<(t[i]<a?1:2)<<" "<<i+1<<" "<<i<<endl;
	}
}