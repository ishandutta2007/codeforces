#include<bits/stdc++.h>
 
using namespace std;

int x;
string p, t;
struct node{
	int parentchar;
	node* parent;
	int index;
	vector <int> terminal;
	node* go[26];
	node* suf;
	node* supersuf;
	node()
	{
		index = 0;
		suf = NULL;
		supersuf = NULL;
		for(int i = 1; i < 10; i++)
		{
			go[i] = NULL;
		}
		parent = NULL;
	}
};
node* global_root;
node* root;
int c = 1;
vector <bool> used;
void go_to(node* &v, int i, int ind){
	if(!v)
	{
		v = new node();
		if(i != 0)
		{
			v -> parentchar = t[i - 1] - '0';
		}
		v -> parent = root;
		v -> suf = global_root;
		v -> supersuf = global_root;
		v -> index = c;
		used.push_back(0);
		c++;
	}
	if(i == t.size())
	{
		used[v -> index] = 1;
		v -> terminal.push_back(ind);
		return;
	}
	root = v;
	go_to(v -> go[t[i] - '0'], i + 1, ind);
}

void build(int i, int sum)
{
	if(sum == x)
	{
		bool flag = true;
		for(int j = 0; j < t.size(); j++)
		{
			int sum1 = 0;
			for(int k = j; k < t.size(); k++)
			{
				sum1 += (t[k] - '0');
				if(x % sum1 == 0 && x != sum1)
				{
					flag = 0;
				}
			}
		}
		if(flag)
		{
			root = global_root;
			go_to(global_root, 0, 0);
		}
		return;
	}
	for(int j = 1; j <= min(9, x - sum); j++)
	{
		t += char(j + '0');
		build(i + 1, sum + j);
		t.pop_back();
	}
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	string s;
	cin >> s;
	cin >> x;
	used.push_back(0);
	global_root = new node();
	global_root -> parent = global_root;
	build(0, 0);
	queue <node*> q;
	global_root -> suf = global_root;
	global_root -> supersuf = global_root;
	vector <vector <int> > matrix(c, vector <int> (11));
	for(int i = 1; i < 10; i++)
	{
		if(!global_root -> go[i])
		{
			matrix[0][i] = 0;
			global_root -> go[i] = global_root;
			continue;
		}
		matrix[0][i] = global_root -> go[i] -> index;
		q.push(global_root -> go[i]);
	}
	node* v;
  	while(q.size() != 0)
  	{
  		v = q.front();
  		q.pop();
  		v -> suf = v -> parent -> suf -> go[v -> parentchar];
  		if(!v -> suf || v -> suf == v)
  		{
  			v -> suf = global_root;
  		}
  		if(v -> suf -> terminal.size() == 0)
  		{
			v -> supersuf = v -> suf -> supersuf;
		}
		else
		{
			v -> supersuf = v -> suf;
		}
		for(int i = 1; i < 10; i++)
		{
			if(!v -> go[i]){
				if(!v -> suf -> go[i])
				{
					v -> go[i] = global_root;
					matrix[v -> index][i] = v -> go[i] -> index;
					continue;
				}
				v -> go[i] = v -> suf -> go[i];
				matrix[v -> index][i] = v -> go[i] -> index;
				continue;
			}
			matrix[v -> index][i] = v -> go[i] -> index;
			q.push(v -> go[i]);
		}
  	}
  	vector <vector <int> > dp(s.size() + 1, vector <int> (c, 1e9));
  	dp[0][0] = 0;
  	for(int i = 1; i <= s.size(); i++)
  	{
  		for(int j = 0; j < c; j++)
  		{
  			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
  			dp[i][matrix[j][s[i - 1] - '0']] = min(dp[i - 1][j], dp[i][matrix[j][s[i - 1] - '0']]);
		}
		for(int j = 0; j < c; j++)
		{
			if(used[j])
			{
				dp[i][j] = 1e9;
			}
		}
	}
	int ans = 1e9;
	for(int j = 0; j < c; j++)
	{
		ans = min(ans, dp[s.size()][j]);
	}
	cout << ans;
	return 0;
}