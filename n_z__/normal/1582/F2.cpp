#include<bits/stdc++.h>
using namespace std;
vector<int>c[10001];
int m[10001];
bitset<10001>v;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	v[0]=1;
	for(int x=0;x<8192;x++)
	c[x].push_back(0),m[x]=8191;
	for(int x=1;x<=n;x++)
	{
	    int y;
	    cin>>y;
	    for(auto q:c[y])
	    {
	        v[q^y]=1;
	        while(m[q^y]>y)
	        c[m[q^y]].push_back(q^y),m[q^y]--;
	    }
	    c[y].clear();
	}
	int ans=0;
	for(int x=0;x<8192;x++)
	ans+=v[x];
	cout<<ans<<endl;
	for(int x=0;x<8192;x++)
	if(v[x])cout<<x<<' ';
}