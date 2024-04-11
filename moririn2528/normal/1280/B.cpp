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
vector<string> v1;
vector<int> va,vb,vc,vd;


int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int tes;
	cin>>tes;
	while(tes--){
		cin>>n>>m;
		v1.clear();
		for(i=0;i<n;i++){
			cin>>sa;
			v1.push_back(sa);
		}
		va.clear(),vb.clear(),vc.clear(),vd.clear();
		b=0;
		for(i=0;i<n;i++){
			a=0;
			for(j=0;j<m;j++){
				if(v1[i][j]=='A')a++;
			}
			if(a==m)va.push_back(i);
			if(a==0)vc.push_back(i);
			b+=a;
		}
		if(b==0){
			cout<<"MORTAL"<<endl;
			continue;
		}
		if(va.size()==n){
			cout<<0<<endl;
			continue;
		}
		for(j=0;j<m;j++){
			a=0;
			for(i=0;i<n;i++){
				if(v1[i][j]=='A')a++;
			}
			if(a==n)vb.push_back(j);
			if(a==0)vd.push_back(j);
		}
		if(va.empty())va.push_back(-1);
		if(vb.empty())vb.push_back(-1);
		if(vc.empty())vc.push_back(-1);
		if(vd.empty())vd.push_back(-1);

		if(va[0]==0 || va.back()==n-1 || vb[0]==0 || vb.back()==m-1){
			cout<<1<<endl;
			continue;
		}
		if(v1[0][0]=='A' || v1[0][m-1]=='A' || v1[n-1][0]=='A' || v1[n-1][m-1]=='A'){
			cout<<2<<endl;
			continue;
		}
		if(va[0]!=-1 || vb[0]!=-1){
			cout<<2<<endl;
			continue;
		}
		
		if(vc[0]==0 && vc.back()==n-1 && vd[0]==0 && vd.back()==m-1){
			cout<<4<<endl;
			continue;
		}
		cout<<3<<endl;

	}
}