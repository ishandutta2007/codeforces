#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[10101][2];

int o1[10101];
int o2[10101];

string get(int k){
	if (k==0) return "Loop";
	else if (k==1) return "Win";
	else return "Lose";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	set<int> s1;
	set<int> s2;
	int k1;
	cin>>k1;
	for (int i=0;i<k1;i++){
		int x;
		cin>>x;
		s1.insert(x);
	}
	int k2;
	cin>>k2;
	for (int i=0;i<k2;i++){
		int x;
		cin>>x;
		s2.insert(x);
	}
	for (int i=1;i<n;i++){
		o1[i]=s1.size();
		o2[i]=s2.size();
	}
	dp[0][0]=2;
	dp[0][1]=2;
	queue<pair<int, int> > q;
	q.push({0, 0});
	q.push({0, 1});
	while (!q.empty()){
		auto ttt=q.front();
		q.pop();
		int x=ttt.F;
		int t=ttt.S;
		if (dp[x][t]==1){// ollaan voittavassa tilassa
			if (t==0){
				for (int y:s2){
					int ne=(x-y+n)%n;
					if (dp[ne][1]) continue;
					o2[ne]--;
					if (o2[ne]==0){
						dp[ne][1]=2;
						q.push({ne, 1});
					}
				}
			}
			else{
				for (int y:s1){
					int ne=(x-y+n)%n;
					if (dp[ne][0]) continue;
					o1[ne]--;
					if (o1[ne]==0){
						dp[ne][0]=2;
						q.push({ne, 0});
					}
				}
			}
		}
		else{
			if (t==0){
				for (int y:s2){
					int ne=(x-y+n)%n;
					if (dp[ne][1]) continue;
					dp[ne][1]=1;
					q.push({ne, 1});
				}
			}
			else{
				for (int y:s1){
					int ne=(x-y+n)%n;
					if (dp[ne][0]) continue;
					dp[ne][0]=1;
					q.push({ne, 0});
				}
			}
		}
	}
	for (int i=1;i<n;i++){
		cout<<get(dp[i][0])<<" ";
	}
	cout<<endl;
	for (int i=1;i<n;i++){
		cout<<get(dp[i][1])<<" ";
	}
	cout<<endl;
}