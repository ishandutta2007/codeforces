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

vector<P> v1;
vector<tuple<LL,LL,int>> v2;
vector<int> vs,vt;

int main(){
	LL n,m,t;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m>>t;
	for(i=0;i<m;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
	}
	for(i=0;i<n;i++){
		cin>>a;
		v2.push_back(make_tuple(a,0,i));
	}
	for(i=0;i<n;i++){
		cin>>a;
		get<1>(v2[i])=a;
	}
	sort(v2.rbegin(),v2.rend());
	sort(v1.rbegin(),v1.rend());
	LL z[3]={0,m+2};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		priority_queue<P,vector<P>,greater<P>> q1;
		bool flag=true;
		vt.assign(m,0);
		c=0;
		for(i=0,j=0;i<(m-1)/z[2]+1;i++){
			for(;j<n;j++){
				if(get<0>(v2[j])<v1[i*z[2]].first)break;
				tie(ignore,a,b)=v2[j];
				q1.push(make_pair(a,b));
			}
			if(q1.empty()){
				flag=false;
				break;
			}
			c+=q1.top().first,a=q1.top().second;
			q1.pop();
			for(k=i*z[2];k<(i+1)*z[2] && k<m;k++){
				vt[v1[k].second]=a+1;
			}
		}
		if(flag && c<=t){
			vs=vt;z[1]=z[2];
		}else z[0]=z[2];
	}
	if(z[1]<=m){
		cout<<"YES"<<endl;
		array_show(vs);
	}else cout<<"NO"<<endl;
}