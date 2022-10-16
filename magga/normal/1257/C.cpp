#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d,k;cin>>n;
    map<long long int,long long int>m;
    long long int ans = 10000000;
    bool flag = false;
    for(long long int i=0;i<n;i++){
        cin>>d;
        if(m.find(d)==m.end()){
            m[d]=i;
        }
        else{
            k = i - m[d];
            flag = true;
            m[d]=i;
            if(k<ans){
                ans= k;
            }
        }
    }
    if(flag){
        cout<<ans+1<<"\n";
    }else{
        cout<<-1<<"\n";
    }
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