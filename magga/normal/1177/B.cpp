#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int k ; cin>>k;
    int i = 0;
    long long int val = k;
    while(true){
        long long int b = pow(10,i);
        b*=9;b*=(i+1);
        if(val>b){
            i++;
            val -= b;        }else{
            i++;
            break;
        }
    }
    val--;
    long long int p = val/i;
    long long int ans = pow(10,i-1);
    
    ans += p;
    //cout<<ans<<endl;
    string s = to_string(ans);
    cout<<s[val%i]<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}