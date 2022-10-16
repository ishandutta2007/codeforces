#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n; cin>>n;
    long long int ans = 0;
    string s ; cin>>s;
    long long int star = s.size();
    long long int end = 0;
    bool b = false;
    for(long long int i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(b){
                end = s.size()-i;
            }else{
                star = i;
                b=true;
                end = s.size()-i;
            }
        }
    }
    if(!b){
        cout<<n<<"\n";
    }else{
        cout<<2*n-min(2*star,2*end-2)<<"\n";
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