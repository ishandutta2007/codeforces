#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> notifs;
int read = 0; // time
int timeread[310000];
int unread[310000];
int ans = 0;
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) unread[i] = timeread[i] = 0;
	for(int i = 1; i <= q; i++){
		int ty;
		scanf("%d", &ty);
		if(ty == 1){
			int x;
			scanf("%d", &x);
			notifs.push_back(x);
			ans++;
			unread[x]++;
		} else if(ty == 2){
			int x;
			scanf("%d", &x);
			ans -= unread[x];
			unread[x] = 0;
			timeread[x] = notifs.size();
		} else if(ty == 3){
			int t;
			scanf("%d", &t);
			while(read < t){
				int x = notifs[read];
				if(read >= timeread[x]){
					unread[x]--;
					ans--;
				}
				read++;
			}
		}
		printf("%d\n", ans);
	}
}