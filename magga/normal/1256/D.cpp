#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<long long int>v;
    for(long long int i=0;i<n;i++){
        if(s[i]=='0'){
            v.push_back(i);
        }
    }
    long long int j=0;
    for(long long int i=0;i<n;i++){
        if(j==v.size()){
            break;
        }
        if(v[i]==j){
            j++;
        }else{
            if(k>v[i]-j){
                k-=v[i]-j;
                v[i]=j;
                j++;
            }else{
                v[i]=v[i]-k;
                break;
            }
        }
    }
    long long int vi =0 ;
    for(long long int i=0;i<n;i++){
        if(vi!=v.size()&& v[vi]==i){
            cout<<'0';
            vi++;
        }
        else{
            cout<<1;
        }    
    
    }
    cout<<"\n";
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