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
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
LL t[5][1000005];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(a==i+1){
			t[0][n-i]+=2*a-n-1;
			t[1][0]++;
			t[2][n-i]--,t[2][n-i+1]--;
		}else if(a<i+1){
			t[0][0]+=i+1-a;
			t[0][n-i]+=2*a-n-1;
			t[1][0]++;
			t[2][n-i]--,t[2][n-i+1]--;
			t[2][n+a-i]+=2;
		}else{
			t[0][0]+=a-(i+1);
			t[0][n-i]+=2*a-n-1;
			t[1][0]--;
			t[2][a-i]+=2;
			t[2][n-i]--,t[2][n-i+1]--;
		}
	}
	for(i=1;i>=0;i--){
		for(j=0;j<n;j++){
			t[i][j+1]+=t[i][j]+t[i+1][j+1];
		}
	}
	a=0;
	for(i=0;i<n;i++){
		if(t[0][a]>t[0][i])a=i;
	}
	cout<<t[0][a]<<" "<<a<<endl;
}