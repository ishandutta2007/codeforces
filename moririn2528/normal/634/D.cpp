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

map<int,int> m1;
vector<P> v1;

int main(){
	LL n,m,d;
	LL i,j,k;
	LL a,b,c;
	LL s=0;
	bool flag=true;
	cin>>n>>d>>m;
	m1[0]=1,m1[n]=1;
	for(i=0;i<m;i++){
		cin>>a>>b;
		v1.push_back(make_pair(b,a));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<m;i++){
		a=v1[i].second;
		m1[a]=1;
		auto itr=m1.find(a);
		itr--;
		b=d,c=a-(itr->first);
		if(c<d)b-=d-c;
		itr++;
		itr++;
		c=(itr->first)-a;
		if(c<d)b-=d-c;
		if(b<0)b=0;
		s+=(LL)b*v1[i].first;
	}
	a=0,b=0;
	for(auto itr=m1.begin();itr!=m1.end();itr++){
		b=a;
		a=itr->first;
		if(a==0)continue;
		if(a-b>d){
			flag=false;
			break;
		}
	}
	if(!flag){
		cout<<-1<<endl;
		return 0;
	}
	cout<<s<<endl;
}