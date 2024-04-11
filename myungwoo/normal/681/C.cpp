#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(v) ((int)(v).size())

int N;
vector <pair<string, int>> ans;
priority_queue <int, vector<int>, greater<int>> que;

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		char buf[15]; string s;
		scanf("%s", &buf); s = buf;
		if (s == "insert"){
			int v; scanf("%d", &v);
			ans.pb({s, v});
			que.push(v);
		}
		else if (s == "removeMin"){
			if (que.empty()){
				ans.pb({"insert", 1});
				que.push(1);
			}
			ans.pb({s, 0});
			que.pop();
		}
		else{
			int v; scanf("%d", &v);
			while (!que.empty() && que.top() < v){
				ans.pb({"removeMin", 0});
				que.pop();
			}
			if (que.empty() || que.top() > v){
				ans.pb({"insert", v});
				que.push(v);
			}
			ans.pb({s, v});
		}
	}
	printf("%d\n", sz(ans));
	for (auto &p: ans){
		if (p.first == "removeMin") puts("removeMin");
		else printf("%s %d\n", p.first.c_str(), p.second);
	}
}