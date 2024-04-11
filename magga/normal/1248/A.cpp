#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,m;
    long long int ne,me,d,ans;
    ans=0;
    ne=0;
    me=0;
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>d;
        if(d%2==0){
            ne++;
        }
    }
    cin>>m;
    for(long long int i=0;i<m;i++){
        cin>>d;
        if(d%2==0){
            me++;
        }
    }
    ans=me*ne+(n-ne)*(m-me);
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}