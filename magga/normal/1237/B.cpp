#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;cin>>n;
    long long int en[n];
    //cout<<"asda";
    long long int ex[n];
    for(long long int i=0;i<n;i++){
        cin>>en[i];
       // cout<<en[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>ex[i];
    }
    set<long long int>voi;
    long long int j = 0;
    for(long long int i=0;i<n;i++){
        if(ex[i]==en[j]){
            j++;
            //cout<<"1"<<" ";
            continue;
        }else if(voi.find(en[j])!=voi.end()){
            j++;
            i--;
            //cout<<"2"<<" ";
            continue;
        }else if(ex[i]!=en[j]){
            voi.insert(ex[i]);
            //cout<<"3"<<" ";
        }
    }
    //cout<<endl;
    cout<<voi.size()<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<1;i++)
    {
       	solve();
    }   
}