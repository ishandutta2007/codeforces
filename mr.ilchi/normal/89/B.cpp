/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

map <string, bool> mark;
int n;
string s;
vector <string> ts;
map <string,int> bord, space;
map <string,char> code;
map <string,pii> store;
map <string,pll> ans;
map < string,vector<string> > adj;

inline void dfs (string &name){
	mark[name]= true;

	vector <string> &g= adj[name];

	for (int i=0;i<(int)g.size();i++) if (!mark[g[i]]) dfs (g[i]);

	ts.push_back (name);
}
/*********************************/
inline pll operator + (const pll &x, const pll &y){
	return pll(x.first + y.first , x.second + y.second);
}
/*********************************/
int main(){

	cin >> n;
	getline (cin, s);

	vector <string> Q;

	for (int o=1;o<=n;o++){
		
		getline (cin,s);

		if (s.substr (0,7)=="Widget "){

			int poi= s.find('(') + 1;

			int e1=0,e2=0;

			while (s[poi]!=',') {e1= e1*10 + s[poi]-'0'; poi++;} poi++;
			while (s[poi]!=')') {e2= e2*10 + s[poi]-'0'; poi++;} 


			string name;

			for (int i=s.find(' ')+1; s[i]!='('; i++) name+= s[i];

			store[name]= pii(e1,e2);

			Q.push_back (name);
		}

		else if (s.substr (0,5)=="HBox "){
			string name;
			
			for (int i=s.find (' ')+1; i<(int)s.size(); i++) name+= s[i];
			
			code[name]= 'H';
			bord[name]= 0; space[name]=0;

			Q.push_back (name);
		}

		else if (s.substr (0,5)=="VBox "){
			
			string name;

			for (int i=s.find (' ')+1; i<(int)s.size(); i++) name+= s[i];
			
			code[name]= 'V';
			bord[name]=0; space[name]=0;

			Q.push_back (name);
		}

		else if (s.find (".set_border")!=s.npos){
			string name;

			for (int i=0; s[i]!='.'; i++) name+= s[i];

			int e1=0;

			for (int i=s.find ('(')+1; s[i]!=')';i++) e1=e1*10 + s[i]-'0';

			bord[name]= e1;
		}

		else if (s.find (".set_spacing")!=s.npos){

			string name;

			for (int i=0; s[i]!='.'	; i++) name+= s[i];

			int e1=0;

			for (int i=s.find ('(')+1; s[i]!=')';i++) e1=e1*10 + s[i]-'0';

			space[name]= e1;
		}

		else{

			string e1,e2;

			for (int i=0; s[i]!='.'; i++) e1+= s[i];
			for (int i=s.find('(')+1; s[i]!=')'; i++) e2+= s[i];

			adj[e1].push_back (e2);
		}
	}

	for (int i=0;i<(int)Q.size();i++) if (!mark[Q[i]]) dfs(Q[i]);

	for (int i=0;i<(int)ts.size();i++){
		
		if (store.find (ts[i])!=store.end())
			ans[ts[i]]= pll (store[ts[i]].first , store[ts[i]].second);

		else{

			vector <string> &g= adj[ts[i]];

			ans [ts[i]]= pll(0,0);

			char type = code[ts[i]];

			for (int j=0; j<(int)g.size();j++)
				if (type=='H')
					ans[ts[i]]= pll (ans[ts[i]].first + ans[g[j]].first , max(ans[ts[i]].second,ans[g[j]].second));
				else
					ans[ts[i]]= pll (max(ans[ts[i]].first,ans[g[j]].first) , ans[ts[i]].second + ans[g[j]].second);

			if (g.size())
				ans[ts[i]]= ans[ts[i]] + pll(2ll*bord[ts[i]] , 2ll*bord[ts[i]]);

			ll tmp= space[ts[i]] * max(0,(int)g.size()-1);

			if (code[ts[i]]=='H')
				ans[ts[i]]= pll (ans[ts[i]].first + tmp, ans[ts[i]].second);
			else
				ans[ts[i]]= pll (ans[ts[i]].first, ans[ts[i]].second + tmp);
		}
	}

	sort (Q.begin(), Q.end());

	for (int i=0;i<(int)Q.size();i++)
		cout << Q[i] << ' ' << ans[Q[i]].first << ' ' << ans[Q[i]].second << endl;

	return 0;
}