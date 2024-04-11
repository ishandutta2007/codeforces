#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int is[2020202];
int g[28][2020202];

string o[202020];

int i2=1;

void add(int x, string&t, int i, int id){
	if (i==(int)t.size()){
		is[x]=id;
	}
	else{
		if (g[t[i]-'a'][x]==0){
			g[t[i]-'a'][x]=i2++;
		}
		add(g[t[i]-'a'][x], t, i+1, id);
	}
}

int dp[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>m;
	string s;
	cin>>s;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>o[i];
		string t=o[i];
		for (int j=0;j<(int)t.size();j++){
			if (t[j]>='A'&&t[j]<='Z'){
				t[j]-='A';
				t[j]+='a';
			}
		}
		add(0, t, 0, i+1);
	}
	dp[0]=1;
	for (int i=1;i<=m;i++){
		int x=0;
		for (int j=i-1;j>=0;j--){
			if (g[s[j]-'a'][x]==0){
				break;
			}
			x=g[s[j]-'a'][x];
			if (is[x]){
				if (dp[j]){
					dp[i]=is[x];
					break;
				}
			}
		}
	}
	vector<string> v;
	int x=m;
	while (x>0){
		v.push_back(o[dp[x]-1]);
		x-=(int)o[dp[x]-1].size();
	}
	for (int i=v.size()-1;i>=0;i--){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}