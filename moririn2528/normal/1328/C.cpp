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

string sa;
string sb,sc;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	while(n--){
		cin>>m;
		cin>>sa;
		bool flag=false;
		sb.clear(),sc.clear();
		for(i=0;i<m;i++){
			a=(int)sa[i]-(int)'0';
			if(flag){
				sb.push_back('0');
				sc.push_back(sa[i]);
			}else if(a==1){
				sb.push_back('1');
				sc.push_back('0');
				flag=true;
			}else{
				char ca=(int)'0'+a/2;
				sb.push_back(ca);
				sc.push_back(ca);
			}
		}
		cout<<sb<<endl;
		cout<<sc<<endl;
	}
}