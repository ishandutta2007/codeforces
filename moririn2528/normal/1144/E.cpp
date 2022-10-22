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

char ca[200005],cb[200005];
int dis[200005];

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	char cc;
	cin>>n;
	cin>>ca>>cb;
	for(i=0;i<n;i++){
		dis[i]=(int)cb[i]-(int)ca[i];
	}
	for(i=n-2;i>=0;i--){
		if(dis[i+1]<0)dis[i+1]+=26,dis[i]--;
	}
	for(i=0;i<n-1;i++){
		if(dis[i]%2==1)dis[i]--,dis[i+1]+=26;
	}
	for(i=n-1;i>=0;i--)dis[i]/=2;
	for(i=n-1;i>=0;i--){
		dis[i]+=(int)ca[i]-(int)'a';
		if(i>0 && dis[i]>=26)dis[i]-=26,dis[i-1]++;
	}
	for(i=0;i<n;i++){
		cc=(char)((int)'a'+dis[i]);
		cout<<cc;
	}
	cout<<endl;
}