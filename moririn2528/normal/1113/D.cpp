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
	cin>>sa;
	a=0;
	for(i=0;i<sa.size();i++){
		if(sa[i]==sa[0])a++;
	}
	if(a>=sa.size()-1){
		cout<<"Impossible"<<endl;
		return 0;
	}
	n=sa.size();
	for(i=1;i<n;i++){
		c=0;
		for(j=0;j<n/2;j++){
			a=(i+j)%n,b=(n+i-j-1)%n;
			if(sa[a]!=sa[b])break;
			if(sa[a]==sa[j])c++;
		}
		if(j==n/2 && c!=n/2){
			cout<<1<<endl;
			return 0;
		}
	}
	cout<<2<<endl;
	return 0;
}