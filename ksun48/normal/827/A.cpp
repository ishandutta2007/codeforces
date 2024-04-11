#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char c[1100000];
string s[1100000];
int k[1100000];
vector<int> x[1100000];
int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int,int> > st;
	int len = 0;
	for(int i = 0; i < n; i++){
		scanf("%s", c);
		int r = strlen(c);
		for(int j = 0; j < r; j++){
			s[i] += c[j];
		}
		scanf("%d", &k[i]);
		for(int j = 0; j < k[i]; j++){
			int a;
			scanf("%d", &a);
			a--;
			x[i].push_back(a);
			st.push_back(make_pair(a,i));
		}
	}
	sort(st.begin(), st.end());
	string ans;
	for(int i = 0; i < st.size(); i++){
		//cout << st[i].first << " " << st[i].second << endl;
		while(ans.size() < st[i].first){
			ans += 'a';
		}
		int z = st[i].second;
		while(ans.size() < st[i].first + s[z].size()){
			ans += s[z][ans.size() - st[i].first];
		}
		//cout << ans << endl;
	}
	cout << ans << endl;

}