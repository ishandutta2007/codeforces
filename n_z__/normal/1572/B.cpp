#include<bits/stdc++.h>
using namespace std;
int s[1000001];
vector<int>q;
void add(int l,int r){
    for(int x=r-2;x>=l;x-=2)q.push_back(x);
    for(int x=l;x<r;x+=2)q.push_back(x);
}
int main(){
    int t;
	cin>>t;
	while(t--){
        int n;
		cin>>n;
        for(int x=1,y;x<=n;x++)
        cin>>y,s[x]=s[x-1]^y;
        if(!s[n])
        if(n&1)add(1,n);
        else for(int x=1;x<=n;x+=2)if(!s[x]){add(1,x);add(x+1,n);break;}
		if(q.size())cout<<"YES"<<endl<<q.size()<<endl;
		else cout<<"NO";
        for(auto x:q)cout<<x<<' ';
        vector<int>().swap(q);
		cout<<endl;
	}
}