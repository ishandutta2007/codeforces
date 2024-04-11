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

string sa;
vector<int> v1;


int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	int tes;
	cin>>tes;
	while(tes--){
		cin>>n;
		cin>>sa;
		v1.clear();
		for(auto ca:sa){
			a=(int)ca-(int)'1';
			v1.push_back(a);
		}
		a=v1.size(),b=v1.size();
		for(i=0;i<n;i++){
			b--;
			if(b<0)b+=MAX;
			a+=b*v1[i];
			b*=v1[i]+1;
			if(a>=MAX)a%=MAX;
			if(b>=MAX)b%=MAX;
			if(v1.size()>n)continue;
			c=v1.size();
			for(j=0;j<v1[i];j++){
				for(k=i+1;k<c;k++){
					if(v1.size()>n)break;
					v1.push_back(v1[k]);
				}
			}
		}
		cout<<a<<endl;
	}
	
}