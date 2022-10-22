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
typedef pair<LL,LL> P;
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

vector<LL> vt[20];
bool used[1<<15];
vector<pair<LL,int>> va[1<<15];
map<LL,int> m1;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	b=0;
	for(i=0;i<n;i++){
		cin>>m;
		for(j=0;j<m;j++){
			cin>>a;
			b+=a;
			m1[a]=i;
			vt[i].push_back(a);
		}
	}
	if(b%n){
		cout<<"No"<<endl;
		return 0;
	}
	b/=n;
	vector<LL> v1(n,0);
	for(i=0;i<n;i++){
		a=b;
		for(auto num:vt[i]){
			a-=num;
		}
		v1[i]=a;
	}
	for(i=0;i<n;i++){
		for(auto num:vt[i]){
			a=num,b=i,c=0;
			while(m1.find(a+v1[b])!=m1.end()){
				a+=v1[b];
				b=m1.find(a)->second;
				if(c&(1<<b))break;
				c|=1<<b;
				if(b==i){
					if(a!=num)c=0;
					break;
				}
			}
			if((c&(1<<i)) && !used[c]){
				used[c]=true;
				va[c].push_back(make_pair(num,b));
			}
		}
	}
	for(i=1;i<(1<<n);i++){
		if(!used[i])continue;
		for(j=1;j<(1<<n);){
			if(i&j){
				j+=i&j;
				continue;
			}
			if(used[j] && !used[i|j]){
				used[i|j]=true;
				va[i|j]=va[i];
				for(k=0;k<va[j].size();k++){
					va[i|j].push_back(va[j][k]);
				}
			}
			j++;
		}
	}
	k=(1<<n)-1;
	if(!used[k]){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	vector<P> vs(n);
	for(auto node:va[k]){
		a=node.first,b=node.second;
		//cout<<a<<" "<<b<<endl;
		while(1){
			vs[b].first=a;
			a+=v1[b];
			c=m1.find(a)->second;
			vs[c].second=b+1;
			b=c;
			if(a==node.first)break;
		}
	}
	for(i=0;i<n;i++){
		cout<<vs[i].first<<" "<<vs[i].second<<endl;
	}
}