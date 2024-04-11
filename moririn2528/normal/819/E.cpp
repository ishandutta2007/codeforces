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

vector<vector<int> > vs;
bool used[305];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	if(n%2==1){
		memset(used,true,sizeof(used));
		for(i=0;i<n/2;i++){
			vs.push_back((vector<int>){3,2*i+1,2*i+2,n});
			vs.push_back((vector<int>){3,2*i+1,2*i+2,n});
		}
	}
	n/=2;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(used[i] && used[j]){
				vs.push_back((vector<int>){4,2*i+1,2*j+1,2*i+2,2*j+2});
				vs.push_back((vector<int>){4,2*i+1,2*j+1,2*i+2,2*j+2});
			}else if(used[i]){
				vs.push_back((vector<int>){4,2*i+1,2*j+1,2*i+2,2*j+2});
				vs.push_back((vector<int>){3,2*i+1,2*j+1,2*j+2});
				vs.push_back((vector<int>){3,2*i+2,2*j+1,2*j+2});
			}else if(used[j]){
				vs.push_back((vector<int>){4,2*i+1,2*j+1,2*i+2,2*j+2});
				vs.push_back((vector<int>){3,2*i+1,2*i+2,2*j+1});
				vs.push_back((vector<int>){3,2*i+1,2*i+2,2*j+2});
			}else{
				vs.push_back((vector<int>){3,2*i+1,2*j+1,2*j+2});
				vs.push_back((vector<int>){3,2*i+2,2*j+1,2*j+2});
				vs.push_back((vector<int>){3,2*i+1,2*i+2,2*j+1});
				vs.push_back((vector<int>){3,2*i+1,2*i+2,2*j+2});
			}
			used[i]=true,used[j]=true;
		}
	}
	cout<<vs.size()<<endl;
	for(auto v1:vs){
		array_show(v1);
	}
}