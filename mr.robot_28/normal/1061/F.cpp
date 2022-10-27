#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int N = 2000;
int n,k,sz[N];
bool vis[N][N];
bool query(int a,int b,int c){
	cout << "? " << a << " " << b << " " << c << endl;
	string s;
	cin >> s;
	return s == "Yes";
}
int get(int a){
	int ret = rng()%n + 1;
	while(ret == a)ret = rng()%n + 1;
	return ret;
}
int main(){
// 	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i = k + 1;i <= n;i++)sz[i] = sz[i/k] + 1;
	for(int i = 0;i <= n;i++)sz[i] = sz[n] - sz[i];
	while(true){
		int a = get(-1);
		int b = get(a);
		if(a > b)swap(a,b);
		if(vis[a][b])continue;
		vis[a][b] = 1;
		vector<int>v;
		int sza = 0,szb = 0;
		for(int i = 1;i <= n;i++)
			if(i != a && i != b){
				if(query(a,i,b))v.push_back(i);
				else{
					if(query(i,a,b))sza++;
					if(query(a,b,i))szb++;
				}
			}
		if(sza + 1 == n){
			cout << "! " << a << endl;
			return 0;
		}
		if(szb + 1 == n){
			cout << "! " << b << endl;
			return 0;
		}
		if(sz[sza] + sz[szb] == v.size() + 1){
			sort(v.begin(),v.end(),[&](int &x,int &y){return query(a,x,y);});
			int d = sz[sza],i = -1;
			while(d)d--,i++;
			printf("! %d\n",v[i]);
			return 0;
		}
	}
	return 0;
}