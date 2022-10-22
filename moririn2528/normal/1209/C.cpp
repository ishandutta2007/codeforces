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

string sa;


int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>sa;
		vector<int> v1(n,2);
		bool flag=false;
		a=-1;
		for(i=0;i<10;i++){
			char ca=(char)((int)'0'+i);
			for(j=0;j<n;j++){
				if(sa[j]==ca){
					if(a<j)a=j,v1[j]=1;
					else flag=true;
				}
			}
			if(flag)break;
		}
		flag=false;
		a=-1;
		for(;i<10;i++){
			char ca=(char)((int)'0'+i);
			for(j=0;j<n;j++){
				if(sa[j]==ca && v1[j]!=1){
					if(a<j)a=j;
					else flag=true;
				}
			}
			if(flag)break;
		}
		if(i<10){
			cout<<"-"<<endl;
			continue;
		}
		for(i=0;i<n;i++){
			cout<<v1[i];
		}
		cout<<endl;
	}
}