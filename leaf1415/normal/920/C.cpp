#include <iostream>
#include <string>

using namespace std;

int parent[200005];
int n;
int a[200005];
string s;

void init()
{
	for(int i = 1; i <= n; i++) parent[i] = i;
}

int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}

bool same(int i, int j)
{
	return root(i) == root(j);
}

void unite(int i, int j)
{
	int root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	
	init();
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1') unite(i+1, i+2);
	}
	
	for(int i = 1; i <= n; i++){
		if(!same(i, a[i])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}