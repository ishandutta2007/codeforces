#include<bits/stdc++.h>
using namespace std;
long long int val( char c ){
    return int(c)-int('0');
}
void solve(){
    long long int n,k;cin>>n>>k;
    string s ; cin>>s;
    string p = s.substr(0,k);
    bool doot = true;
    for( long long int i=0;i<n;i++){
       // 
        if( val(s[i]) < val(p[i%k]) ){
            doot = true;
            break;
        }
        if( val(s[i]) > val( p[i%k] ) ){
            doot = false;
            break;
        }
    }
    if(!doot){
        for(long long int i=k-1;i>=0;i--){
            if(val(p[i]) == 9){
                p[i] = '0';
            }else{
                p[i] = char( val(p[i]) + 1 + int('0') );
                break;
            }
        }    
    }
    cout<<n<<"\n";
    for(long long int i=0;i<n;i++){
        cout<<p[i%k];
    }
    cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}