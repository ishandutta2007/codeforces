#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;cin>>n;
    long long int a[n];
    long long int b[n];
    bool flag = false;
    bool cont = false;
    long long int max = -1;
    for(long long int i=0;i<n;i++)cin>>a[i];
    for(long long int i=0;i<n;i++)cin>>b[i];
    for(long long int i=0;i<n;i++){
        if(a[i]==b[i]){
            cont = false;
            continue;
        }
        if(!flag){
            cont = true;
            flag = true;
            max = b[i]-a[i];
            if(max<0){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(flag && cont && b[i]-a[i]==max){
            continue;
        }
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
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