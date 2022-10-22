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

string sa,sb,ss;
int num[3300000];
int z[3300000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	n--;
	cin>>sa>>sb;
	for(i=0;i<n;i++){
		if(sa[i]=='N')num[n-i-1]=0;
		if(sa[i]=='E')num[n-i-1]=1;
		if(sa[i]=='W')num[n-i-1]=2;
		if(sa[i]=='S')num[n-i-1]=3;
	}
	for(i=0;i<n;i++){
		if(sb[i]=='N')num[n+i]=3;
		if(sb[i]=='E')num[n+i]=2;
		if(sb[i]=='W')num[n+i]=1;
		if(sb[i]=='S')num[n+i]=0;
	}
	for(i=1,j=0;i<n*2;){
		for(;j<n && i+j<2*n;j++){
			if(num[i+j]!=num[j])break;
		}
		z[i]=j;
		if(j==0){
			i++;
			continue;
		}
		for(k=1;;k++){
			i++,j--;
			if(z[k]<j)z[i]=z[k];
			else break;
		}
	}
	#ifdef MORIRIN
	array_show(num,2*n);
	array_show(z,2*n);
	#endif //MORIRIN
	for(i=n;i<n*2;i++){
		if(z[i]+i>=2*n){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}