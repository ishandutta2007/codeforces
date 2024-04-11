#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int q[1010],id[1010];
int n,m;
vector<PII> list[1010];
bool ok[1010];

int main() {
	cin>>n;
	Rep(i,n)cin>>q[i];
	cin>>m;
	Rep(i,m){
		int u,v,c;
		cin>>u>>v>>c;
		list[v-1].pb(MP(u-1,c));
	}	
	Rep(i,n)id[i]=i;
	Rep(i,n)Rep(j,i)if(q[id[i]]>q[id[j]])swap(id[i],id[j]);
	//Rep(i,n)cout<<id[i]<<endl;
	long long total=0;
	Rep(k,n){
		int i=id[k];
		if(k==0)ok[i]=true;
		else{
			int costmin=1000000000;
			Rep(z,list[i].size()){
				int fa=list[i][z].fi;
				int cost=list[i][z].se;
				if(ok[fa] && costmin>cost)costmin=cost;
			}	
			if(costmin==1000000000){
				cout<<-1<<endl;
				return 0;	
			}
			total+=costmin;
			ok[i]=true;
		}	
	}
	cout<<total<<endl;
	return 0;	
}