#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 305;

int n;
int input[N];
int test[N];

int readmask(){
	int ret = 0;
	for(int i=0; i<3; i++){
		int x;
		cin>>x;
		ret = ret<<1|x;
	}
	return ret;
}

int source[11];
vector<int>bucket[11];
queue<int>q;

void empty_bucket(int mask){
	if(mask == 0)return;
	for(int i=0; i<bucket[mask].size(); i++){
		q.push(bucket[mask][i]);
	}
	bucket[mask].clear();
}

bool ct[N];
vector<pair<int,int> >cd;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		input[i] = readmask();
		if(i > 1){
			bucket[input[i]].pb(i);
		}
	}
	for(int i=1; i<=n; i++){
		test[i] = readmask();
	}
	
	for(int i=0; i<7; i++)source[i] = -1;
	ct[1] = 1;
	source[7] = 1;
	empty_bucket(7);
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		ct[now] = 1;
		cd.pb({source[input[now]], now});
		int output = input[now] & test[now];
		
		if(source[output] == -1){
			source[output] = now;
			empty_bucket(output);
		}
		
		// check merges
		for(int i=1; i<=4; i<<=1){
			if(source[i] == -1)continue;
			for(int j=i<<1; j<=4; j<<=1){
				if(source[j] == -1)continue;
				if(source[i|j] == -1){
					// if there is actually someone who needs this mask
					if(bucket[i|j].size() > 0){
						int s = source[i|j] = bucket[i|j].back();
						bucket[i|j].pop_back();
						ct[s] = 0;
						cd.pb({source[i], s});
						cd.pb({source[j], s});
						empty_bucket(i|j);
					}
				}
			}
		}
	}
	
	bool fail = false;
	for(int i=1; i<7; i++){
		if(bucket[i].size() > 0){
			fail = true;
		}
	}
	
	if(fail)cout << "Impossible" << endl;
	else{
		cout << "Possible" << endl;
		for(int i=1; i<=n; i++)cout << ct[i] << " ";
		cout << endl;
		cout << cd.size() << endl;
		for(int i=0; i<cd.size(); i++){
			cout << cd[i].F << " " << cd[i].S << endl;
		}
	}
	
	return 0;
}