#include<bits/stdc++.h>
using namespace std;
vector<int>c(1<<24);
int main(){
    //cout<<clock()<<endl;
	int n;
	cin>>n;
	for(int x=0;x<n;x++)
    {
        string s;
        cin>>s;
        int now=0;
		for(int y=0;y<3;y++)
        now|=1<<(s[y]-'a');
		c[now]++;
	}
	int ans=0;
    //cout<<clock()<<endl;
	for(int y=0;y<24;y++)
    for(int x=0;x<(1<<24);x++)
	if(x&(1<<y))c[x]+=c[x-(1<<y)];
    //cout<<clock()<<endl;
    for(int x=0;x<(1<<24);x++)
    ans^=(n-c[x])*(n-c[x]);
	cout<<ans<<endl;
}