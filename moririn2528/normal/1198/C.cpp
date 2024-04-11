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

int deg[300005];
bool used[300005];
vector<P> path[300005];
vector<int> s1,s2;

int main(){
	int t;
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		s1.clear(),s2.clear();
		for(i=0;i<3*n;i++)deg[i]=0,used[i]=false,path[i].clear();
		for(i=0;i<m;i++){
			cin>>a>>b;
			a--,b--;
			path[a].push_back(make_pair(b,i+1));
			path[b].push_back(make_pair(a,i+1));
			deg[a]++,deg[b]++;
		}
		for(i=0;i<3*n;i++){
			if(used[i])continue;
			used[i]=true;
			if(deg[i]==0){
				s2.push_back(i+1);
				continue;
			}
			for(j=0,k=-1;j<path[i].size();j++){
				a=path[i][j].first,b=path[i][j].second;
				if(used[a])continue;
				if(k==-1){
					s1.push_back(b),k=a,used[a]=true;
				}
				deg[a]--;
			}
			for(j=0;j<path[k].size();j++){
				a=path[k][j].first;
				if(used[a])continue;
				deg[a]--;
			}
			
		}
		if(s1.size()>=n){
			cout<<"Matching"<<endl;
			for(i=0;i<n;i++)printf("%d%c",s1[i],(i!=n-1?' ':'\n'));
		}else{
			cout<<"IndSet"<<endl;
			for(i=0;i<n;i++)printf("%d%c",s2[i],(i!=n-1?' ':'\n'));
			
		}
	}
}