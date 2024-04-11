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
#include<cassert>
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
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int t[220000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>m;
	while(m--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>t[i];
		}
		a=0,b=0;
		for(i=1;i<n;i++){
			if(t[i]!=t[i-1])a++;
			else b=i;
		}
		if(t[0]!=t[n-1])a++;
		if(a==0){
			for(i=0;i<n;i++){
				t[i]=1;
			}
			cout<<1<<endl;
			array_show(t,n);
			continue;
		}
		if(n%2==0){
			for(i=0;i<n;i++){
				t[i]=i%2+1;
			}
			cout<<2<<endl;
			array_show(t,n);
			continue;
		}
		if(a==n){
			for(i=0;i<n;i++){
				t[i]=i%2+1;
			}
			t[n-1]=3;
			cout<<3<<endl;
			array_show(t,n);
			continue;
		}
		for(i=0,a=1;i<n;i++){
			a++;
			if(i==b)a--;
			else if(a>2)a-=2;
			t[i]=a;
		}
		cout<<2<<endl;
		array_show(t,n);
	}
}