#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[303030];
int p[303030];
int u[303030];

int xx[303030];

vector<int> lol[303030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	set<pair<int, int> > es;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		es.insert(minmax(a, b));
	}
	vector<int> eli;
	priority_queue<pair<int, int> > qq;
	qq.push({0, 1});
	while (!qq.empty()){
		auto t=qq.top();
		qq.pop();
		int x=t.S;
		if (u[x]) continue;
		u[x]=1;
		eli.push_back(x);
		for (int nx:g[x]){
			p[nx]++;
			qq.push({p[nx], nx});
		}
	}
	if ((int)eli.size()!=n){
		cout<<"YES"<<endl;
		return 0;
	}
	assert((int)eli.size()==n);
	
	for (int i=1;i<=n;i++) {
		p[i]=0;
		u[i]=0;
	}
	qq.push({0, eli.back()});
	eli.clear();
	while (!qq.empty()){
		auto t=qq.top();
		qq.pop();
		int x=t.S;
		if (u[x]) continue;
		u[x]=1;
		eli.push_back(x);
		for (int nx:g[x]){
			p[nx]++;
			qq.push({p[nx], nx});
		}
	}
	assert((int)eli.size()==n);
	
	reverse(eli.begin(), eli.end());
	xx[eli[0]]=1;
	int fn=0;
	for (int x:eli){
		u[x]=2;
		for (int nx:g[x]){
			if (xx[nx]==0&&x!=eli[0]){
				fn=1;
// 				cout<<"fo "<<x<<endl;
			}
		}
		if (!fn){
			for (int nx:g[x]){
				if (u[nx]==1&&xx[nx]==xx[x]&&xx[x]==2){
// 					cout<<"minu "<<nx<<endl;
					xx[x]--;
					break;
				}
			}
		}
// 		cout<<"t "<<x<<" "<<xx[x]<<endl;
		int ff=0;
		for (int nx:g[x]){
			if (u[nx]==2) ff=1;
		}
		if (x!=eli[0]&&ff==0){
// 			cout<<"taa"<<endl;
			for (int nx:g[x]){
				if (xx[nx]!=0){
					xx[x]=xx[nx]+1;
				}
			}
			for (int nx:g[x]){
				if (xx[nx]==0){
					xx[nx]=xx[x];
				}
			}
		}
		else{
			if (!fn){
				for (int nx:g[x]){
					if (u[nx]==1){
						xx[nx]=xx[x]+1;
					}
				}
			}
			else{
				for (int nx:g[x]){
					if (xx[nx]==0){
						xx[nx]=xx[x]+1;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (xx[i]<=0){
			cout<<"NO"<<endl;
			return 0;
		}
		for (int nx:g[i]){
			if (abs(xx[i]-xx[nx])>1){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		lol[xx[i]].push_back(i);
	}
	for (int i=1;i<=n;i++){
		for (int a:lol[i]){
			for (int b:lol[i]){
				if (a<b){
					if (!es.count({a, b})){
						cout<<"NO"<<endl;
						return 0;
					}
				}
			}
			for (int b:lol[i+1]){
				if (!es.count(minmax(a, b))){
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++){
		cout<<xx[i]<<" ";
	}
	cout<<endl;
}