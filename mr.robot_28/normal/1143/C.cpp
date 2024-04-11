#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <vector <int> > A;
vector <int> G, P;
void dfs(int v)
{
	int sum = 0;
	for(int i = 0; i < A[v].size(); i++)
	{
		sum += P[A[v][i]];
		dfs(A[v][i]);
	}
	sum += P[v];
	if(sum == 0)
	{
		G.push_back(v);
	}
	//cout << v << " " << sum << endl;
}
int main(){
    int n;
    cin >> n;
    A.resize(n);
    P.resize(n);
    int pred = -1;
    for(int i = 0; i < n; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	if( a != -1)
    	{
    	A[a - 1].push_back(i);
    	}
		else
		{
			pred = i;
		}
		P[i] = 1- b;
	}
	dfs(pred);
	sort(G.begin(), G.end());
	for(int i = 0; i < G.size(); i++)
	{
		cout << G[i] + 1 << " ";
	}
	if(G.size() == 0)
	{
		cout << -1;
	}
    return 0;
}