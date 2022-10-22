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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

vector<P> v[2],vs[2];
int s[1000005][3];
int sn;

int main(){
	int n;
	LL a,b,c;
	int i,j,k;
	LL t[2]={0};
	cin>>n;
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			cin>>a;
			v[i].push_back(make_pair(a,j));
			t[i]+=a;
		}
		sort(v[i].begin(),v[i].end());
	}
	if(t[0]!=t[1]){
		cout<<"NO"<<endl;
		return 0;
	}
	
	a=0;
	for(i=0;i<n;i++){
		b=v[1][i].first-v[0][i].first;
		if(b>0)vs[0].push_back(make_pair(v[0][i].second,b));
		if(b<0)vs[1].push_back(make_pair(v[0][i].second,-b));
		a+=b;
		if(a<0)break;
	}
	if(i!=n){
		cout<<"NO"<<endl;
		return 0;
	}
	for(i=0,j=0;i<vs[0].size();i++){
		for(;j<vs[1].size();j++){
			if(vs[1][j].second==0)continue;
			a=min(vs[0][i].second,vs[1][j].second);
			vs[0][i].second-=a,vs[1][j].second-=a;
			s[sn][0]=vs[0][i].first+1,s[sn][1]=vs[1][j].first+1,s[sn][2]=a;
			sn++;
			if(vs[0][i].second==0)break;
		}
	}
	cout<<"YES"<<endl;
	cout<<sn<<endl;
	for(i=0;i<sn;i++){
		array_show(s[i],3);
	}
}