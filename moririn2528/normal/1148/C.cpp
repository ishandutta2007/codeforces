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

int p[300005];
int w[300005];
vector<P> vs;

void move(int a,int b){
	swap(p[a],p[b]),swap(w[p[a]],w[p[b]]);
	vs.push_back(make_pair(a+1,b+1));
}

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		a--;
		p[i]=a,w[a]=i;
	}
	for(i=0;i<n/2;i++){
		if(i==w[i])continue;
		if(w[i]-i>=n/2)move(i,w[i]);
		else if(w[i]<n/2)move(w[i],n-1),move(i,n-1);
		else{
			a=w[i];
			move(a,0),move(0,n-1),move(i,n-1),move(0,a);
		}
	}
	for(i=n/2;i<n;i++){
		if(i==w[i])continue;
		a=w[i];
		move(0,a),move(0,i),move(0,a);
	}
	cout<<vs.size()<<endl;
	for(i=0;i<vs.size();i++){
		a=vs[i].first,b=vs[i].second;
		cout<<a<<" "<<b<<endl;
	}
}