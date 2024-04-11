#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

void gg(){
	puts("No");
	exit(0);
}

const int N=16;
const int X=1<<N;

typedef pair<LL,int> P;
map<LL,int> mp;
map<LL,bool> vis;
LL sum[N]={0};
bool go[X]={false};
vector<P> fafa[X];

vector<P> w;
bool ed=false;
LL fl;
int dfs(LL v){
	map<LL,int>::iterator it=mp.find(v);
	if(it==mp.end()){
		fl=v;
		return vis.count(v)?0:-1;
	}
	int id=it->second;
	// cerr<<id<<endl;
	mp.erase(v);
	vis[v]=true;
	int tres=dfs(v-sum[id]);
	vis.erase(v);
	if(!ed){
		if((tres>>id)&1)return -1;
		if(v==fl){
			ed=true;
		}
		w.push_back(P(v,id));
		return tres|(1<<id);
	}
	else{
		return tres;
	}
}

bool res[X]={true,false};
int ch[X];
P ans[N];
int main(){
	ios::sync_with_stdio(false);
	int k;
	cin>>k;
	LL tsum=0;
	F(i,0,k-1){
		int n;
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			sum[i]+=x;
			tsum+=x;
			mp[x]=i;
			// cerr<<mp[x]<<endl;
		}
	}
	if(tsum%k!=0)gg();
	LL w=tsum/k;
	F(i,0,k-1)sum[i]-=w;
	while(!mp.empty()){
		::w.clear();
		ed=false;
		int res=dfs(mp.begin()->first);
		// cerr<<res<<" "<<ed<<endl;
		if(res==-1)continue;
		// cerr<<res<<endl;
		go[res]=true;
		fafa[res]=::w;
	}
	F(i,1,(1<<k)-1){
		for(int s=i;s;s=(s-1)&i){
			if(res[i^s]&&go[s]){
				res[i]=true;
				ch[i]=s;
				break;
			}
		}
	}
	if(!res[(1<<k)-1])gg();
	cout<<"Yes"<<endl;
	for(int mk=(1<<k)-1;mk;){
		int x=ch[mk];
		F(i,0,fafa[x].size()-1){
			P qaq=fafa[x][i];
			ans[qaq.second]=P(qaq.first,fafa[x][(i+1)%fafa[x].size()].second+1);
		}
		mk^=x;
	}
	F(i,0,k-1){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}