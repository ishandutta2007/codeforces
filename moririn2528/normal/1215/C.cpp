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

string sa,sb;
int num[2];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	cin>>sa>>sb;
	for(i=0;i<n;i++){
		if(sa[i]==sb[i])continue;
		if(sa[i]=='a')num[0]++;
		else num[1]++;
	}
	if((num[0]+num[1])%2!=0){
		cout<<-1<<endl;
		return 0;
	}
	if(num[0]%2==1){
		cout<<(num[0]+num[1])/2+1<<endl;
		for(i=0;i<n;i++){
			if(sa[i]==sb[i])continue;
			if(sa[i]=='a'){
				cout<<i+1<<" "<<i+1<<endl;
				sa[i]='b',sb[i]='a';
				break;
			}
		}
	}else cout<<(num[0]+num[1])/2<<endl;
	num[0]=-1,num[1]=-1;
	for(i=0;i<n;i++){
		if(sa[i]==sb[i])continue;
		if(sa[i]=='a')j=0;
		else j=1;
		if(num[j]==-1)num[j]=i;
		else{
			cout<<num[j]+1<<" "<<i+1<<endl;
			num[j]=-1;
		}
	}
}